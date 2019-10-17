/****************************************************************************
@file:count.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 13:31 
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

bool op(int e)
{
	if (e%2==0) {
		cout << e << "%2==0" << endl;
		return true;
	}

	return false;
}

int main(int argc, char **argv)
{

	cout<<"hello world!"<<endl;

	vector<int> v = { 1,2,3,4,5,6};

	cout << std::count_if(v.begin(), v.end(), op) << endl;

	return 0;
}

