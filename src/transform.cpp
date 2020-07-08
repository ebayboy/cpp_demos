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

void show(vector<int> v)
{
	for_each(v.begin(), v.end(), [](auto i){ cout << i << " "; });
	cout << endl;
}

int main(int argc, char **argv)
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2(v1.size());
	vector<int> v3(v1.size());

	//show v3
	show(v3);

	//show v1
	show(v1);

	//一元变换
	//v1 transform -> v2
	std::transform(v1.begin(), v1.end(), v2.begin(), [](int it){ return it + 1; });
	show(v2);

	//二元变换
	//transform v1, v2 -> v3(v1 + v2)
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int a, int b){ return a + b; });
	show(v3);


	return 0;
}

