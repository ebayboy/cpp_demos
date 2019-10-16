/****************************************************************************
@file:string_ssign.cpp 
@author:ebayboy@163.com 
@date:2019-10-16 15:38 
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
	string str1("123456");
	string str;

	cout << "str1: " << str1 << endl;
	cout << "str1.npos: " << str1.npos << endl;

	str.assign(str1);
	cout << "str: "  << str << endl;

	str.assign(str1, 3, 3);
	cout << str << endl;

	str.assign(str1, 2, str1.npos);
	cout << str << endl;

	str.assign(5, 'X');
	cout << str << endl;

	str.assign(str1.begin(), str1.end());
	cout << str << endl;

	return 0;
}

