/****************************************************************************
@file:for_each.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 13:14 
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

void func_op(int & i)
{
	cout << i << endl;
	i = 5;
}

int main(int argc, char **argv)
{

	cout<<"hello world!"<<endl;

	vector<int> v;

	for (int i = 1; i < 5; i++) {
		v.push_back(i);
	}

	std::for_each(v.begin(), v.end(), func_op);


	cout << "after func1 set: " << endl;
	for (size_t j = 0; j < v.size(); j++) {
		cout << v[j] << endl;
	}

	return 0;
}

