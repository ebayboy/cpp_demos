#ifndef __CURL_WRAPPER_H
#define __CURL_WRAPPER_H

int curl_http_get(const char *url);
int curl_http2_get(const char *url, int use_ssl);

#endif

