/****************************************************************************
@file:equal.cpp
@author:ebayboy@163.com
@date:2019-10-17 14:24
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
    vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = { 3, 4, 5};

	auto it = std::equal(v1.begin() + 2, v1.end(), v2.begin());

	cout << "v1.begin() + 2): " << *(v1.begin() + 2) << endl;
	cout << it << endl;

    return 0;
}

