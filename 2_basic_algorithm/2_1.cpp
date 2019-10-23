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

//枚举算法


//1. 韩信点兵
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

//2. 白鸡问题
static void test_2_1_2()
{
	int x, y, z;

	cout <<"x y z: " << endl;
	for (x = 0; x <= 100/5; x++) {
		for (y = 0; y <= 100/3; y++) {
			z = (100 - 5*x - 3*y)*3;
			if (z >= 0) {
				printf("%d %d %d\n", x, y, z);
			}
		}
	}
}

//3. 求水仙花数
static void test_2_1_3()
{
	int sum = 0, temp = 0;

	cout << __func__ << endl;
	for (int x=1; x <= 9; x++ )	{
		for (int y = 0; y <=9; y++) {
			for (int z = 0; z <=9; z++) {
				temp = x*100 + y*10 + z;
				sum = x*x*x + y*y*y + z*z*z;
				if (temp == sum) {
					cout << sum << " ";
				}
			}
		}
	}

	cout << endl;
}

int main(int argc, char **argv)
{
	clock_t start;

	start = clock();
	test_2_1_1();
	cout << "use " << clock() - start << " ms" << endl;

	start = clock();
	test_2_1_2();
	cout << "use " << clock() - start << " ms" << endl;

	start = clock();
	test_2_1_3();
	cout << "use " << clock() - start << " ms" << endl;

	return 0;
}

