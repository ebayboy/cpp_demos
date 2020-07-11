/****************************************************************************
@file:string_test.cpp 
@author:ebayboy@163.com 
@date:2019-10-31 14:42 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

//#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	string str1 = "aaa";
	size_t a = 100;

	str1 += " bbb";

	str1 += std::to_string(a);

	cout << "str:" << str1 << endl;

	return 0;
}

