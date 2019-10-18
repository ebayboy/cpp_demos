/****************************************************************************
@file:bin_search.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 19:42 
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

int main(int argc, char **argv)
{
	vector<int> v = {1,2,3,4,5};

	bool it = std::binary_search(std::begin(v), std::end(v), 5);
	cout << it << endl;

	return 0;
}

