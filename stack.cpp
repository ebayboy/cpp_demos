/****************************************************************************
@file:stack.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 09:46 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

//stack 先进后出

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	stack<int> s;

	//
	for (int i = 1; i < 5; i++) {
		s.push(i);
	}

	cout << "size: " << s.size() << endl;

	while(!s.empty()) {
		cout << "top: " <<  s.top() << endl;
		s.pop();
	}

	return 0;
}

