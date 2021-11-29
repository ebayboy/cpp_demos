#!/bin/bash

# ***************************************************************************
# * 
# * @file:test_http2_no_ssl.sh 
# * @author:ebayboy@163.com 
# * @date:2021-11-21 00:40 
# * @version 1.0  
# * @description: Shell script 
# * @Copyright (c)  all right reserved 
#* 
#**************************************************************************/ 

HOST="https://nghttp2.org"

curl -k -I -v ${HOST}  --http2-prior-knowledge

exit 0

