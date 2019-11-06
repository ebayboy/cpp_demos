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


//给定数组a[]={ 2,1,4,5,7,6,3,9 }, 
//在数组a中查找3,
//使用二分查找算法（非递归方式实现）

int bsearch(int *a, size_t size, int v)
{
	int mid = 0;

	for (size_t i=0; i < size; i++) 
	{
		mid = (size - i)/ 2;
		cout << "mid: " << mid << endl;
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
				printf("before: %d %d\n", *(a + i), *(a + j));
				tmp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = tmp;
				printf("after: %d %d\n", *(a + j), *(a + i));
			}
		}
	}
}


int main(int argc, char **argv)
{
	int a[8]={ 2,1,4,5,7,6,3,9 };

	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;

	bubble_sort((int *)&a, sizeof(a)/sizeof(int));

	for (auto i : a) {
		cout << i << " ";
	}

	cout << endl;

	return 0;
}

