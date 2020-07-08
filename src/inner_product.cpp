/****************************************************************************
@file:inner_product.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 17:03 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

//计算两个范围的元素的内积
//inner_product

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	vector<int> v1{ 1, 3, 5};
	vector<int> v2{ 2, 4, 6};

	// 1*2 + 3*4 + 5*6 =  2 + 12 + 30 = 44 
	auto ret = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
	cout << "ret: " << ret << endl;

	//self op2(+) op1()
	//initValue op1 (a1 op2 b1) op1 (a2 op2 a2) op1 ...
	//(1+2) * (3+4) * (5+6) = 3 * 7 * 11 = 3 * 77 = 231
	auto ret2 = std::inner_product(v1.begin(), v1.end(), v2.begin(), 1, 
			[](int a, int b) { return a*b; }, 
			std::plus<>{});
	cout << "ret2: " << ret2 << endl;

	return 0;
}

