#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
	int res = 0;
	const char *https_url = "https://example.com/";
	const char *http_url = "http://www.hangzhou.gov.cn";

	res = curl_http_get(http_url);
	if (res != 0) {
		fprintf(stderr, "Error:curl_http_get");
	} else {
		printf("curl:[%s] ok!\n", http_url);
	}

	return 0;
}
