/****************************************************************************
@file:element.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 13:40 
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
	vector<int> v = {3, 4, 1,2, 5};

	//cmp1
	vector<int>::iterator it = min_element(v.begin(), v.end());
	cout << "it: " << *it << endl;

	return 0;
}

