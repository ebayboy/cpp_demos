/****************************************************************************
@file:cstdio.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 13:49 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <cstdio>
#include <cctype>
#include <cstdlib> //exit qsort

using namespace std;

//qsort

#define DEBUG 

int compar(const void *va, const void *vb)
{
	int *a = (int *)va;
	int *b = (int *)vb;

	if ((*a) > (*b)) {
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	int age = 0;
	char name[512] = {0};
	char c;

	scanf("%d", &age);
	printf("age:%d\n", age);

	scanf("%s", name);
	printf("name:%s\n", name);

	c = getchar();
	printf("c=[%c]\n", c);

	char d = 'd';
	printf("toupper(d)=%c tolower(d):%c)\n", toupper(d), tolower(d));


	int arr[] = { 3, 5, 2 , 4 , 1};
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compar);
	for (size_t i = 0; i < sizeof(arr)/sizeof(int); i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	exit(0);

	return 0;
}

