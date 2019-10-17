/****************************************************************************
@file:swap.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 18:43 
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


void show(vector<int> v, std::string msg)
{
	cout << endl << msg << endl;

	std::for_each(v.begin(), v.end(), [](int v){ cout << v << " "; });
	cout << endl;
}

int main(int argc, char **argv)
{
	vector<int> v1 = { 1,2,3};
	vector<int> v2 = { 4,5,6};

	show(v1, "v1:");
	show(v2, "v2:");

	std::swap(v1, v2);

	show(v1, "v1:");
	show(v2, "v2:");

	return 0;
}

