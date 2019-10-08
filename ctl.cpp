/****************************************************************************
@file:ctl.cpp 
@author:ebayboy@163.com 
@date:2019-10-08 10:36 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector <int> vec;

	cout << "vec size:" << vec.size() << endl;

	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}

	cout << "extended size:" << vec.size() << endl;

	for (int i =0; i < 5; i++) {
		cout << "value:" << vec[i] << endl;
	}

	for (vector<int>::iterator v = vec.begin(); v != vec.end(); v++) {
		cout << "iter value: " << *v << endl;
	}

	return 0;
}

