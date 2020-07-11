/****************************************************************************
@file:partial_sum.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 16:57 
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

int main(int argc, char **argv)
{
	vector<int> v { 3, 1 , 5, 2, 4};
	vector<int> ret(10);

	for (auto i : v) cout << i << " ";
	cout << endl;

	//v: 3 1 5 2 4 
	//ret: 3 4 9 11 15 0 0 0 0 0 
	//partial_sum: 将每个元素和其先前所有元素的组合， 结果复制到pos中
	std::partial_sum(v.begin(), v.end(), ret.begin());
	
	for (auto i : ret) cout << i << " ";
	cout << endl;

	return 0;
}

