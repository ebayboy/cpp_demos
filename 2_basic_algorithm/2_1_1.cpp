/****************************************************************************
@file:2_1_1.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 18:09 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 

//韩信点兵
static void test_2_1_1()
{
	int x;

	for (x = 1; ;x++) {
		if (x%3==1 && x%5==2 && x%7==3)  {
			cout << x << endl;
			return ;
		}
	}
}

int main(int argc, char **argv)
{
	clock_t start;

	start = clock();
	test_2_1_1();
	cout << "use " << clock() - start << " ms" << endl;

	return 0;
}

