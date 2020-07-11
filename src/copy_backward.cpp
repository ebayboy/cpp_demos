/****************************************************************************
@file:copy_backward.cpp
@author:ebayboy@163.com
@date:2019-10-17 16:43
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


void show(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(int argc, char **argv)
{
    vector<int> v1 = {1,2,3};
	vector<int> v2 = {4,5};
	show (v2);

	v2.resize(v2.size() + v1.size());
	show (v2);

	std::copy_backward(v1.begin(), v1.end(), v2.end());

	show(v2);

    return 0;
}

