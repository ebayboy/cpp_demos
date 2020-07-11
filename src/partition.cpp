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

	// 1 2 3 4 5 -> 4 2 3 1 5 
	// 交换元素， 将满足条的移动到前面
    std::partition(std::begin(v), std::end(v), [](int i)
    {
        if (i % 2 == 0)
        {
            return true;
        }
        return false;
    });
    show(v);
	cout << endl;

    vector<int> v1 = { 1,2,3,4,5 };
	show(v1);

	//1 2 3 4 5 ->  2 1 3 4 5 -> 2 4 3 1 5 
    std::stable_partition(std::begin(v1), std::end(v1), [](int i)
    {
        if (i % 2 == 0)
        {
            return true;
        }
        return false;
    });
	show(v1);

    return 0;
}

