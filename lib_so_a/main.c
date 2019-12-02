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
	printf("The add:%d\n",add(a,b));
	printf("The sub:%d\n",sub(a,b));
	printf("The mul:%d\n",mul(a,b));
	printf("The div:%d\n",div(a,b));

	return 0;
}

