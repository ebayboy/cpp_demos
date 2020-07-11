/****************************************************************************
@file:priority_queue.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 09:53 
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
	cout<<"hello world!"<<endl;

#if 1
	std::priority_queue< int, std::vector<int>, std::greater<int> > pq;
#else
	std::priority_queue< int, std::vector<int>> pq;
#endif

	pq.push(3);
	pq.push(5);
	pq.push(1);

	while(!pq.empty()) {
		cout << "size: " << pq.size() << " top: " << pq.top() << endl;
		pq.pop();
	}


	return 0;
}

