#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* somewhat unix-specific */
#include <sys/time.h>
#include <unistd.h>

/* curl stuff */
#include <curl/curl.h>
#include <curl/mprintf.h>

//#define CURL_HTTP_X_DEBUG

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
#ifdef CURL_HTTP_X_DEBUG
	printf("%s:%d size:[%d]\n", __func__, __LINE__, size * nmemb);
#endif
	return size * nmemb;
}

/* ======================== FOR HTTP ============================= */
int curl_http_get(const char *url)
{
	int ret = 0;
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK) {
#ifdef CURL_HTTP_X_DEBUG
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
#endif
			ret = -1;
		}
		curl_easy_cleanup(curl);
	}

	return ret;
}

/* =========================== FOR HTTP2 =========================== */
struct transfer {
	CURL *easy;
};

static void http2_dump(const char *text, unsigned char *ptr, size_t size, char nohex)
{
	size_t i;
	size_t c;

	unsigned int width = 0x10;

	if(nohex) {
		/* without the hex output, we can fit more on screen */
		width = 0x40;
	}

#ifdef CURL_HTTP_X_DEBUG
	fprintf(stderr, "%s, %lu bytes (0x%lx)\n", text, (unsigned long)size, (unsigned long)size);
#endif

	for(i = 0; i<size; i += width) {
#ifdef CURL_HTTP_X_DEBUG
		fprintf(stderr, "%4.4lx: ", (unsigned long)i);
#endif

		if(!nohex) {
			/* hex not disabled, show it */
			for(c = 0; c < width; c++)
				if(i + c < size) {
#ifdef CURL_HTTP_X_DEBUG
					fprintf(stderr, "%02x ", ptr[i + c]);
#endif
				} else {
#ifdef CURL_HTTP_X_DEBUG
					fputs("   ", stderr);
#endif
				}
		}

		for(c = 0; (c < width) && (i + c < size); c++) {
			/* check for 0D0A; if found, skip past and start a new line of output */
			if(nohex && (i + c + 1 < size) && ptr[i + c] == 0x0D && ptr[i + c + 1] == 0x0A) {
				i += (c + 2 - width);
				break;
			}
#ifdef CURL_HTTP_X_DEBUG
			fprintf(stderr, "%c", (ptr[i + c] >= 0x20) && (ptr[i + c]<0x80)?ptr[i + c]:'.');
#endif
			/* check again for 0D0A, to avoid an extra \n if it's at width */
			if(nohex && (i + c + 2 < size) && ptr[i + c + 1] == 0x0D && ptr[i + c + 2] == 0x0A) {
				i += (c + 3 - width);
				break;
			}
		}
		fputc('\n', stderr); /* newline */
	}
}


static int http2_trace(CURL *handle, curl_infotype type, char *data, size_t size, void *userp)
{
	const char *text;
	struct transfer *t = (struct transfer *)userp;
	(void)handle; /* prevent compiler warning */

	switch(type) {
		case CURLINFO_TEXT:
#ifdef CURL_HTTP_X_DEBUG
			fprintf(stderr, "== Info: %s", data);
#endif
			/* FALLTHROUGH */
		default: /* in case a new one is introduced to shock us */
			return 0;

		case CURLINFO_HEADER_OUT:
			text = "=> Send header";
			break;
		case CURLINFO_DATA_OUT:
			text = "=> Send data";
			break;
		case CURLINFO_SSL_DATA_OUT:
			text = "=> Send SSL data";
			break;
		case CURLINFO_HEADER_IN:
			text = "<= Recv header";
			break;
		case CURLINFO_DATA_IN:
			text = "<= Recv data";
			break;
		case CURLINFO_SSL_DATA_IN:
			text = "<= Recv SSL data";
			break;
	}

#ifdef CURL_HTTP_X_DEBUG
	http2_dump(text, (unsigned char *)data, size, 1);
#endif

	return 0;
}


static void http2_setup(struct transfer *t, const char *url, int use_ssl)
{
	CURL *hnd;
	hnd = t->easy = curl_easy_init();

	curl_easy_setopt(hnd, CURLOPT_URL, url);
	curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_data);


#ifdef CURL_HTTP_X_DEBUG
	/* please be verbose */
	curl_easy_setopt(hnd, CURLOPT_VERBOSE, 1L);
	curl_easy_setopt(hnd, CURLOPT_DEBUGFUNCTION, http2_trace);
	curl_easy_setopt(hnd, CURLOPT_DEBUGDATA, t);
#endif

	if (use_ssl) {
		curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2_0);
		/* we use a self-signed test server, skip verification during debugging */
		curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYHOST, 0L);
	} else {
		curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE);
	}

#if (CURLPIPE_MULTIPLEX > 0)
	/* wait for pipe connection to confirm */
	curl_easy_setopt(hnd, CURLOPT_PIPEWAIT, 1L);
#endif

}

int curl_http2_get(const char *url, int use_ssl)
{
	struct transfer trans[32];
	int i;
	int still_running = 0; /* keep number of running handles */
	int num_transfers = 5;
	CURLM *multi_handle;

	/* init a multi stack */
	multi_handle = curl_multi_init();

	for(i = 0; i < num_transfers; i++) {
		http2_setup(&trans[i], url, use_ssl);
		/* add the individual transfer */
		curl_multi_add_handle(multi_handle, trans[i].easy);
	}

	curl_multi_setopt(multi_handle, CURLMOPT_PIPELINING, CURLPIPE_MULTIPLEX);

	do {
		CURLMcode mc = curl_multi_perform(multi_handle, &still_running);
		if(still_running) {
			/* wait for activity, timeout or "nothing" */
			mc = curl_multi_poll(multi_handle, NULL, 0, 1000, NULL);
		}
		if(mc) {
#ifdef CURL_HTTP_X_DEBUG
			fprintf(stderr, "error!\n");
#endif
			break;
		}
	} while(still_running);

	for(i = 0; i < num_transfers; i++) {
		curl_multi_remove_handle(multi_handle, trans[i].easy);
		curl_easy_cleanup(trans[i].easy);
	}

	curl_multi_cleanup(multi_handle);

	return 0;
}



