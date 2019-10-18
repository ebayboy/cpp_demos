/****************************************************************************
@file:bound.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 19:45 
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
	vector<int> v = { 1, 3, 5 , 7, 9 };

	SHOW_VEC(v);

	//返回第一个大于等于value的元素位置, v是有序的
	auto it = std::lower_bound(std::begin(v), std::end(v), 7);
	cout << *it << endl;

	return 0;
}

