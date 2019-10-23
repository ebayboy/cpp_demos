/****************************************************************************
@file:op.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 08:44 
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
	vector<int> v { 1, 2, 2};

	//int ret = std::accumulate(std::begin(v), std::end(v), 0, [](int a, int b) { return a+b;});
	//int ret = std::accumulate(std::begin(v), std::end(v), 0, std::plus<> {});
	//int ret = std::accumulate(std::begin(v), std::end(v), 100, std::minus<> {});
	//int ret = std::accumulate(std::begin(v), std::end(v), 100, std::multiplies<> {});
	int ret = std::accumulate(std::begin(v), std::end(v), 100, std::divides<> {});
	
	cout << ret << endl;

	return 0;
}

