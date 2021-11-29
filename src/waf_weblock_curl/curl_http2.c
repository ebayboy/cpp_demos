
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

#include "curl_wrapper.h"

//TODO: 实际使用的是HTTP/1.1交互， 是libcurl没有集成编译libnghttp2导致不支持http2？
int main(int argc, char **argv)
{
	const char * ssl_url= "https://nghttp2.org";
	const char * url= "http://10.0.2.16:18888";

#if 0
	curl_http2_get(ssl_url, 1);
#else
	curl_http2_get(url, 0);
#endif

	return 0;
}
