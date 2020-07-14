/****************************************************************************
@file:find.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 14:07 
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

#define DEBUG 

bool op(int e)
{
	if (e%2 == 0) {
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	vector<int> v = {3,1,2,4,5,1};

	auto it = std::find(v.begin(), v.end(), 1);

	cout << *it << endl;

	//find_if
	auto it2 = std::find_if(v.begin(), v.end(), op);
	cout << *it2 << endl;

	return 0;
}

