/****************************************************************************
  @file:main.c
  @author:ebayboy@163.com
  @date:2019-12-02 18:36
  @version 1.0
  @description: cpp file
  @Copyright (c)  all right reserved
 **************************************************************************/

#include <stdio.h>
#include "test.h"

int main()
{
	int a,b;

	printf("please input a and b\n");
	scanf("%d %d",&a,&b);
	printf("The test_add:%d\n",test_add(a,b));
	printf("The test_sub:%d\n",test_sub(a,b));
	printf("The test_mul:%d\n",test_mul(a,b));
	printf("The test_div:%d\n",test_div(a,b));

	return 0;
}

