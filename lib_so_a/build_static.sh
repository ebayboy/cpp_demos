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

gcc -c  -fPIC -o test_la.o test.c
ar rcs libtest.a test_la.o
gcc -o app_static main.c -L. -ltest

exit 0

