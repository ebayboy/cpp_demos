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

gcc -c -o test_ld.o -fPIC test.c

gcc -shared -o libmyshare.so test_ld.o

gcc -o app_share main.c -L. -lmyshare 

exit 0

