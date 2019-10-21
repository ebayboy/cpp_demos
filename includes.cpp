/****************************************************************************
@file:includes.cpp 
@author:ebayboy@163.com 
@date:2019-10-21 11:25 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	set<int> v1 = { 1,2,3,4,5 }; 
	set<int> v2 = { 2,3,4 }; 

	auto ret = std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
	cout << ret << endl;

	return 0;
}

