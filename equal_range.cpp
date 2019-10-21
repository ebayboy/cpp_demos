/****************************************************************************
@file:equal_range.cpp 
@author:ebayboy@163.com 
@date:2019-10-21 10:09 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

#include "common.h"

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	vector<int> v = { 1, 3, 5, 5, 5, 7};
	std::sort(v.begin(), v.end());
	SHOW_VEC(v);

	std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

	//C++ STL equal_range 函数说明
	//equal_range 返回范围[first,last)内等于指定值val的子范围的迭代器。
	//注意的是使用这个函数的前提是范围[first,last)内的元素是有序的。
	
	bounds = std::equal_range(std::begin(v), std::end(v), 5);
	cout << "bounds at positions " << (bounds.first - v.begin());
	cout << " and " << (bounds.second - v.begin()) << endl;

	return 0;
}

