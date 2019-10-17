/****************************************************************************
@file:transform.cpp 
@author:ebayboy@163.com 
@date:2019-10-17 17:42 
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
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2(v1.size());

	//show v1
	for_each(v1.begin(), v1.end(), [](auto i){ cout << i << " "; });
	cout << endl;

	//v1 transform -> v2
	std::transform(v1.begin(), v1.end(), v2.begin(), [](int it){ return it + 1; });


	//show v2
	for_each(v2.begin(), v2.end(), [](auto i){ cout << i << " "; });
	cout << endl;

	return 0;
}

