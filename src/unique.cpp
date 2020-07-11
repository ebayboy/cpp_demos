/****************************************************************************
@file:unique.cpp
@author:ebayboy@163.com
@date:2019-10-18 10:05
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
    for_each(std::begin(v), std::end(v), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

int main(int argc, char **argv)
{

    cout<<"hello world!"<<endl;
    vector<int> v1 = { 1, 2, 3, 3, 5 };

	//移除相邻元素
    std::unique(std::begin(v1), std::end(v1));
	show(v1);

	//移除相邻元素，并拷贝到pos
	vector<int> v3(10);
    vector<int> v2 = { 1, 2, 3, 3, 5, 3 };
	std::sort(std::begin(v2), std::end(v2));
	std::unique_copy(std::begin(v2), std::end(v2), std::begin(v3));
	show(v3);

    return 0;
}

