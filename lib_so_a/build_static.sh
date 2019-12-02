#!/bin/bash

# ***************************************************************************
# * 
# * @file:build_static.sh 
# * @author:ebayboy@163.com 
# * @date:2019-12-02 18:38 
# * @version 1.0  
# * @description: Shell script 
# * @Copyright (c)  all right reserved 
#* 
#**************************************************************************/ 

CFLAGS=""

gcc -c $CFLAGS test.c -o test.o.s
ar rcs libtest.a test.o.s
gcc -o app_static main.c -L. -ltest

exit 0

