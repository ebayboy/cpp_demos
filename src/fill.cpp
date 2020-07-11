/****************************************************************************
@file:fill.cpp
@author:ebayboy@163.com
@date:2019-10-18 08:49
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
        cout << i<< " ";
    });
    cout << endl;
}

int main(int argc, char **argv)
{
    vector<int> v(10);

    std::fill(v.begin(), v.end(), 1);
	show(v);

    vector<int> v2(10);
	show(v2);
	std::fill_n(v2.begin() + 2, 3, 3);
	show(v2);

    return 0;
}

