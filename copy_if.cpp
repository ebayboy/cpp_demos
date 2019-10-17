/****************************************************************************
@file:copy_if.cpp
@author:ebayboy@163.com
@date:2019-10-17 17:06
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
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
}

int main(int argc, char **argv)
{
    vector<int> v1 = {1,2,3,4,5};
	vector<int> v2(10);

	show(v2);

	//lamba function
	std::copy_if(v1.begin(), v1.end(), v2.begin(), [](int i){ return (i % 2 == 0); } );
	cout << "after copy_if: " << endl;
	show(v2);

	return 0;
}

