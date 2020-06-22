/****************************************************************************
@file:bublle_sort.cpp 
@author:ebayboy@163.com 
@date:2019-11-20 00:39 
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

void show_array(int *a, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(a + i) << " ";
	cout << endl;
}

void bubble_sort(int *a, int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				//swap
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main(int argc, char **argv)
{
	int a[9] = {3, 1, 5, 4, 6, 2, 7, 9, 8};

	show_array((int *)&a, 9);

	bubble_sort((int *)&a, 9);

	show_array((int *)&a, 9);

	return 0;
}
