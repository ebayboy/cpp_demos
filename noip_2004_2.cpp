/****************************************************************************
@file:noip_2004_2.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 09:19 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	std::priority_queue <int, std::vector<int>, std::greater<> > q;

	int n, temp, r = 0;

	cin >> n;
	cout << "n: " << n << endl;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push(temp);
	}

	while(q.size() > 1) {
		int a = q.top();
		q.pop();

		int b = q.top();
		q.pop();

		cout << "a : " << a <<  " b :" << b << endl;

		q.push(a+b);
		r += a + b;

		cout << "q.size: " << q.size() <<  " r : " << r <<  endl;
	}

	cout << r << endl;

	return 0;
}

