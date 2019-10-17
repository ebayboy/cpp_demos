/****************************************************************************
@file:search.cpp
@author:ebayboy@163.com
@date:2019-10-17 14:14
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
    vector<int> v1 = {1,2,3,4,3,3,5};
    vector<int> v2 = {3,4,5,6,7};

    //search
    auto it = std::search(v1.begin(), v1.end(), v2.begin(), v2.begin() + 3);
    if (it != v1.end())
    {
        cout << it - v1.begin() << endl;
    }

    //search_n
    auto it2 = std::search_n(v1.begin(), v1.end(), 2, 3);
    if (it2 != v1.end())
    {
        cout << it2 - v1.begin() << endl;
    }

    return 0;
}

