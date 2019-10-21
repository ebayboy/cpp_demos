/****************************************************************************
@file:merge.cpp 
@author:ebayboy@163.com 
@date:2019-10-21 10:59 
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
	vector<int> v = { 1, 2, 3};
	vector<int> v1 = { 4, 5, 6};
	vector<int> r(10);

	SHOW_VEC(v);
	SHOW_VEC(v1);
	SHOW_VEC(r);

	std::merge(v.begin(), v.end(), v1.begin(), v1.end(), r.begin());
	cout << "after merge v & v1: " << endl;
	SHOW_VEC(r);

	return 0;
}

