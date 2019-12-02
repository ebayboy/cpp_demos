#!/bin/bash

# ***************************************************************************
# * 
# * @file:build_dynamic.sh 
# * @author:ebayboy@163.com 
# * @date:2019-12-02 18:41 
# * @version 1.0  
# * @description: Shell script 
# * @Copyright (c)  all right reserved 
#* 
#**************************************************************************/ 

gcc -o libmyshare_la.so -L. -ltest -shared
gcc -o app_share_la main.c -L. -lmyshare_la -ltest -L.

exit 0

