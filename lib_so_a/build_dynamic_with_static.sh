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

gcc -c -fPIC test2.c -o test2.o

gcc -shared test2.o -L. -ltest -o libmyshare_la.so

gcc -o app_share_la main2.c -lmyshare_la  -L.

exit 0

