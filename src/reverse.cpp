/****************************************************************************
@file:reverse.cpp
@author:ebayboy@163.com
@date:2019-10-18 11:06
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

    cout<<"hello world!"<<endl;
    vector<int> v1 = { 1,2,3,4,5 };
	show(v1);

	std::reverse(std::begin(v1), std::end(v1));
	show(v1);

	vector<int> v2(10);
	std::reverse_copy(std::begin(v1), std::end(v1), std::begin(v2));
	show(v2);

    return 0;
}

