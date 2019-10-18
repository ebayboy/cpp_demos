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
	SHOW_VEC(v);

	//sort by default
	std::sort(std::begin(v), std::end(v));
	SHOW_VEC(v);

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

	SHOW_VEC(v1);

	//partial sort
	vector<int> v2 = { 4,5, 1, 3, 2};
	SHOW_VEC(v2);
	std::partial_sort(std::begin(v2), std::begin(v2) + 2, std::end(v2));
	SHOW_VEC(v2);

	//nth_element 高效版排序算法
	//4 5 1 3 2 6  -> 2 1 3 4 5 6 
	vector<int> v3 = { 4,5, 1, 3, 2, 6};
	SHOW_VEC(v3);
	cout << "std::begin(v3) + 3: " << *(v3.begin() + 3) << endl;
	std::nth_element(std::begin(v3), std::begin(v3) + 3, std::end(v3));
	SHOW_VEC(v3);

	return 0;
}

