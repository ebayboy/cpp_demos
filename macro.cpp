/****************************************************************************
@file:macro.cpp 
@author:ebayboy@163.com 
@date:2019-09-30 17:28 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

#define MKSTR(x) #x

#define CONCAT(x,y) x##y

int main(int argc, char **argv)
{
	int xy = 100;

	cout<<"MIN(3, 5):" << MIN(3, 5) << endl;

	cout<<"MKSTR(hello c++):" << MKSTR(hello c++) << endl;

	cout<<"CONCAT(x,y):" << CONCAT(x,y) << endl;

	return 0;
}

