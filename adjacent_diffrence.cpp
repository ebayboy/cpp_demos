/****************************************************************************
@file:adjacent_diffrence.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 16:49 
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
	vector<int> v { 1, 4, 3, 2};
	vector<int> ret(10);
	vector<int> ret2(10);

	for (auto i : v) cout << i << " ";
	cout << endl;

	//default op  = this_element - prev_element;
	std::adjacent_difference(v.begin(), v.end(), ret.begin());
	for (auto i : ret) cout << i << " ";
	cout << endl;

	//self op
	std::adjacent_difference(v.begin(), v.end(), ret2.begin(), [](int a, int b) { return a + b; });
	for (auto i : ret2) cout << i << " ";
	cout << endl;

	return 0;
}

