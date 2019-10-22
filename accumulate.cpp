/****************************************************************************
@file:accumulate.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 16:34 
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
	std::vector<int> v { 1, 4, 3};

	for (auto i : v) cout << i <<" ";
	cout << endl;

	auto ret = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });
	cout << ret << endl;

	return 0;
}

