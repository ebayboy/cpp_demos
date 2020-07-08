/****************************************************************************
@file:random_shufle.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 11:22 
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
    for_each(v.begin(), v.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

int main(int argc, char **argv)
{
	vector<int> v = { 1,2,3,4,5 };
	show(v);

	std::random_shuffle(std::begin(v), std::end(v));
	show(v);

	return 0;
}

