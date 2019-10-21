/****************************************************************************
@file:set_intersection.cpp 
@author:ebayboy@163.com 
@date:2019-10-21 12:44 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <set>

#include "common.h"

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	set<int> s1 = { 1, 2, 3, 4, 5 };
	set<int> s2 = { 3, 4, 5, 6, 7 };
	set<int> result;

	//求两个集合的交集
	std::set_intersection(std::begin(s1), std::end(s1), std::begin(s2), std::end(s2), std::inserter(result, std::begin(result)));
	SHOW_VEC(result);

	return 0;
}

