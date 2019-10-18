/****************************************************************************
@file:remove.cpp
@author:ebayboy@163.com
@date:2019-10-18 09:30
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
    std::for_each(std::begin(v), std::end(v), [](int i) { cout << i << " "; }); 
    cout << endl;
}

int main(int argc, char **argv)
{

    cout<<"hello world!"<<endl;
    vector<int> v = { 1,2,3,4,5 };
    show(v);

    // 1 2 3 4 5 -> 1 2 4 5 5
    std::remove(std::begin(v), std::end(v), 3);
    show(v);

    // 1 2 3 4 5 -> 1 3 4 5 5  -> 1 3 5 4 5 
    vector<int> v2 = { 1,2,3,4,5 };
    std::remove_if(std::begin(v2), std::end(v2), [](int i)
    {
        if (i % 2 == 0)
        {
            cout << "move: " << i << endl;
            return true;
        }
        return false;
    });
    show(v2);

    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4(10);
	//remove copy !=3 to v4
    remove_copy(v3.begin(), v3.end(), v4.begin(), 3);
    show(v4);


    v4.assign(10, 0);
    show(v4);
    std::remove_copy_if(v3.begin(), v3.end(), v4.begin(), [](int i)
    {
        if (i%2 == 0)
        {
            return true;
        }
        return false;
    });
	show(v4);

    return 0;
}

