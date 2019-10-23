/****************************************************************************
@file:rand.cpp 
@author:ebayboy@163.com 
@date:2019-10-23 14:53 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	srand(time(NULL));

	for (size_t i = 0; i < 1000; i ++ ) {
		printf("%d ", rand()%1024);
	}

	return 0;
}

