/****************************************************************************
@file:macro2.cpp 
@author:ebayboy@163.com 
@date:2019-09-30 17:37 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	cout << "__FILE__:" << __FILE__ << endl;
	cout << "__LINE__:" << __LINE__ << endl;
	cout << "__DATE__:" << __DATE__ << endl;
	cout << "__TIME__:" << __TIME__ << endl;

	cout << "[" << __DATE__ << __TIME__ << "] " << __FILE__ << ":" << __LINE__ << endl;

	return 0;
}

