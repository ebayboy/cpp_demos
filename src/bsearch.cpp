/****************************************************************************
@file:bsearch.cpp
@author:ebayboy@163.com
@date:2019-11-05 14:35
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


//给定数组a[]={ 1,2,3,4,5,6,7,8,9 },
//在数组a中查找3,
//使用二分查找算法（非递归方式实现）

int bsearch(int *a, int size, int v)
{
    int mid = 0;

	//mode: 标志位，对进入大或者小的条件判断后，
	//不再进入相反的判断流程， 以防数组不存在这个元素导致死循环
	int mode = 0;

	mid  = size/2;

    while (mid >= 0 && mid < size)
    {
        if (*(a + mid) == v)
        {
            return mid;
        }
        else if (*(a + mid) < v) 
        {
			//mode 1
			if (mode == 2) {
				return -1;
			}
            mid = ((mid + 1) + size)/2;
			mode = 1;
        }
        else
        {
			if (mode == 1) {
				return -1;
			}
			//mode 2
            mid = mid/2;
			mode = 2;
        }
    }

    return -1;
}

void bubble_sort(int *a, int size)
{
    int i, j;
    int tmp;

    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if (*(a + j) < *(a + i))
            {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
}


int main(int argc, char **argv)
{
    int a[9]= { 2,1,4,5,7,6,9,3,8 };

    bubble_sort((int *)&a, sizeof(a)/sizeof(int));

    int pos = bsearch((int*)&a, sizeof(a)/sizeof(int), 3);
    cout << "pos: " << pos << endl;

    return 0;
}

