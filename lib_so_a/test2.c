/****************************************************************************
@file:test2.c 
@author:ebayboy@163.com 
@date:2019-12-02 23:39 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <stdio.h>
#include <unistd.h>

#include "test.h"

int test2_add(int a, int b)
{
	return 2*test_add(a, b);
}


