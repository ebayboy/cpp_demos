/****************************************************************************
@file:copy.cpp
@author:ebayboy@163.com
@date:2019-10-17 16:19
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
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

int main(int argc, char **argv)
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};

    //保存v2大小
    size_t putpos = v2.size();

    cout << "before resive v2 size: " << v2.size() <<endl;

    //申请可以容纳v1.size()的空间
    v2.resize(v2.size() + v1.size());
    cout << "after resive: " << v2.size() <<endl;
    show(v2);

    //将v1元素拷贝到v2的末尾
    std::copy(v1.begin(), v1.end(), v2.begin() + putpos);
    cout << "after copy show v2:" << endl;
    show(v2);

    return 0;
}

