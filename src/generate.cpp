/****************************************************************************
@file:generate.cpp
@author:ebayboy@163.com
@date:2019-10-18 08:54
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
	cout << endl;
    std::for_each(v.begin(), v.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}


int main(int argc, char **argv)
{
    vector<int> v(10);

	show(v);

	std::generate(v.begin(), v.end(), std::rand);
	show(v);

	vector<int> v2(10);
	std::generate_n(std::begin(v2) + 2, 3, std::rand);
	show(v2);

    return 0;
}

