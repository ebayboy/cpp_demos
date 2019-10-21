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

	SHOW_VEC(v);

	std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

	bounds = std::equal_range(std::begin(v), std::end(v), 5);
	std::cout << "bounds at positions " << (bounds.first - v.begin());
	//cout << "first: " << bounds->first - v.begin() << endl;
	cout << "second: " << bounds->second - v.begin() << endl;

	return 0;
}

