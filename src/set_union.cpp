/****************************************************************************
@file:set_union.cpp 
@author:ebayboy@163.com 
@date:2019-10-21 11:47 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <set>
#include <algorithm>

#include "common.h"

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	set<int> s1 ={ 1,3,5};
	set<int> s2 ={ 2,3,6};
	set<int> sr;

	std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sr, std::begin(sr)));
	SHOW_VEC(sr);

	return 0;
}

