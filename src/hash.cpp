/****************************************************************************
@file:hash.cpp 
@author:ebayboy@163.com 
@date:2020-08-21 18:57 
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
	std::hash<std::string> hash_str;
	std::string food {"corned beef"};
	std::cout << "corned beef hash is " << hash_str(food) << std::endl;

	return 0;
}
