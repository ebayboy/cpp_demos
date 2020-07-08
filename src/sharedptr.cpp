/****************************************************************************
@file:sharedptr.cpp 
@author:ebayboy@163.com 
@date:2020-06-23 12:17 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	shared_ptr<string> p1(new string ("hello"));
	cout << "p1.use_count:" << p1.use_count() << endl;

	shared_ptr<string> p2 = p1;

	cout<< "*p1:" << *p1 << "p1.use_count:" << p1.use_count() <<endl;
	cout<< "*p2:" << *p2 <<endl;

	return 0;
}

