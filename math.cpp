/****************************************************************************
@file:math.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 15:11 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

#define PI 3.1415926

#define DEBUG 

void test_sin(int deg)
{
	double ret = sin(deg * PI/180);
	printf("sin:%.2f\n", ret);
}

void test_cos(int deg)
{
	double ret = cos(deg * PI/180);
	printf("cos:%.2f\n", ret);
}

void test_tan(int deg)
{
	double ret = tan(deg * PI/180);
	printf("cos:%.2f\n", ret);
}

int main(int argc, char **argv)
{
	test_sin(30);

	test_cos(60);

	test_tan(45);

	return 0;
}

