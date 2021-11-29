#!/bin/bash

CFLAGS=" -DCURL_HTTP_X_DEBUG"

if [ ! -d "curl" ];then
	echo 'tar -xzf curl.tar.gz'
	tar -xzf curl.tar.gz
fi

if [ ! -d "nghttp2" ];then
	echo 'tar -xzf nghttp2.tar.gz'
	tar -xzf nghttp2.tar.gz 
fi

#build curl_http
gcc -g curl_http.c curl_wrapper.c ./curl/lib/libcurl.a ./nghttp2/lib/libnghttp2.a -I ./curl/include/ -I ./nghttp2/include/ -lnettle -lgnutls -lssl -lcrypto -lssl -lcrypto -lldap -llber -lz -lpthread -o curl_http $CFLAGS

#build curl_http2
gcc -g curl_http2.c curl_wrapper.c ./curl/lib/libcurl.a ./nghttp2/lib/libnghttp2.a -I ./curl/include/ -I ./nghttp2/include/ -lnettle -lgnutls -lssl -lcrypto -lssl -lcrypto -lldap -llber -lz -lpthread -o curl_http2 $CFLAGS

