/****************************************************************************
@file:bound.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 19:45 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

//lower_bound和upper_bound都是返回大于value的元素的位置

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
	vector<int> v = { 1, 3, 5 ,5, 5, 5, 7, 9 };

	SHOW_VEC(v);

	//返回第一个小于等于value的元素位置, v是有序的
	vector<int>::iterator it = std::lower_bound(std::begin(v), std::end(v), 5);
	cout << "lower_bound at index: " << it - std::begin(v) << endl;
	cout << "item: " << *it << endl;

	//返回第一个大于value的元素位置
	vector<int>::iterator it1 = std::upper_bound(std::begin(v), std::end(v), 5);
	cout << endl << "upper_bound at index: " << it1 - std::begin(v) << endl;
	cout << "item: " << *it1 << endl;

	return 0;
}

