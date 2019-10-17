/****************************************************************************
@file:queue.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 09:24 
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
	queue<int> q;

	//push
	for (int i = 1; i < 5; i++)	{
		q.push(i);
	}

	cout << "front: " << q.front() << endl;
	cout << "back: " << q.back() << endl;
	cout << "size: " << q.size() << endl;

	while(!q.empty()) {
		cout << "front: " << q.front() << endl;
		q.pop();
	}

	return 0;
}

