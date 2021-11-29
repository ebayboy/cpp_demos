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

HOST=10.0.2.16:18888

curl -I -v http://${HOST}  --http2-prior-knowledge

exit 0

