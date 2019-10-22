/****************************************************************************
@file:for_auto.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 15:53 
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
	vector<int> v { 1,2,3,5,2,0 };

	for (auto it : v) 
		cout << it << " ";
	cout << endl;

	return 0;
}

