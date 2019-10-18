/****************************************************************************
@file:sort.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 18:09 
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

#include "common.h"

#define DEBUG 

int main(int argc, char **argv)
{
	cout<<"hello world!"<<endl;

	vector<int> v = {4, 5, 1, 2, 3};
	SHOW_VEC(v, "v: ");

	//sort by default
	std::sort(std::begin(v), std::end(v));
	SHOW_VEC(v, "v");

	//sort by self function
	vector<int> v1 = {4, 5, 1, 2, 3};
#if 0

	std::sort(std::begin(v1), std::end(v1), [](int a, int b){ 
			if(a > b) {
				return 1;
			}
			return 0;
	});

#else

	//stable edition
	std::stable_sort(std::begin(v1), std::end(v1), [](int a, int b){ 
			if(a > b) {
				return 1;
			}
			return 0;
	});

#endif

	SHOW_VEC(v1, "v1");

	//partial sort
	vector<int> v2 = { 4,5, 1, 3, 2};
	SHOW_VEC(v2, "v2");
	std::partial_sort(std::begin(v2), std::begin(v2) + 2, std::end(v2));
	SHOW_VEC(v2, "v2");
	
	return 0;
}

