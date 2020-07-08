/****************************************************************************
@file:noip_2004_2.cpp
@author:ebayboy@163.com
@date:2019-10-23 09:19
@version: 1.0
@description: cpp file
@Copyright (c)  all right reserved
**************************************************************************/
//题目： 合并果子 2004NOIP第二题
//有n堆果子( 1 << n << 10000)果子， 每堆重量已知。每次可以把两堆果子合并，
//该次消耗的体力为两堆果子的重量之和。
//在合并果子时总共消耗的体力等于每次合并所消耗的体力之和。
//现在要把这堆果子合并成一堆。
//求最小消耗的体力？

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define DEBUG

int main(int argc, char **argv)
{
    std::priority_queue <int, std::vector<int>, std::greater<> > q;

    int n, temp, r = 0;

    cin >> n;
    cout << "n: " << n << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }

    while(q.size() > 1)
    {
        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        cout << "a : " << a <<  " b :" << b << endl;

        q.push(a+b);
        r += a + b;

        cout << "q.size: " << q.size() <<  " r : " << r <<  endl;
    }

    cout << r << endl;

    return 0;
}

