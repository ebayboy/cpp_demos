/****************************************************************************
@file:rotate.cpp 
@author:ebayboy@163.com 
@date:2019-10-18 11:09 
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
	vector<int> v1 = {1,2,3,4,5};
	show(v1);

	//1 2 3 4 5 -> 4 5 1 2 3
	cout << "std::begin(v1) + 2): " << *(v1.begin() + 2) << endl;

	//将[first->middle) 和 [midlle->last]进行交换
	//将[1,2,)和(3,4,5)交换
	//结果: 3 4 5 1 2 
	std::rotate(std::begin(v1), std::begin(v1) + 2, std::end(v1));
	show(v1);


	//rotate_copy 将旋转后的结果拷贝到v4, v3旋转后不变
	vector<int> v3 = {1,2,3,4,5};
	vector<int> v4(10);
	std::rotate_copy(std::begin(v3), std::begin(v3) + 2, std::end(v3), std::begin(v4));
	cout << "show v3: " << endl;
	show(v3);

	cout << "show v4: " << endl;
	show(v4);

	return 0;
}

