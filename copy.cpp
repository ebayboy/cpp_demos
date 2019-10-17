/****************************************************************************
@file:copy.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 16:19 
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
	vector<int> v1 = { 1, 2, 3};
	vector<int> v2 = { 4, 5};

	std::copy(v1.begin(), v1.end(), v2.begin());

	cout << "v1.size(): " << v1.size() << endl;
	cout << "v2.size(): " << v2.size() << endl;

	cout << "show v2:" << endl;
	for (size_t i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}

	cout << endl;

	return 0;
}

