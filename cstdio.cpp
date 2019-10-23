/****************************************************************************
@file:cstdio.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 13:49 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

#include <cstdio>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	int age = 0;
	char name[512] = {0};
	char c;

	scanf("%d", &age);
	printf("age:%d\n", age);

	scanf("%s", name);
	printf("name:%s\n", name);

	c = getchar();
	printf("c=[%c]\n", c);

	return 0;
}

