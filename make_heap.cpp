/****************************************************************************
@file:make_heap.cpp 
@author:ebayboy@163.com 
@date:2019-10-22 15:51 
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
	//===Max heap
	std::vector<int> v { 3, 2, 4, 1, 5, 9 };

	cout << "initially, v: ";
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	std::make_heap(std::begin(v), std::end(v));
	cout << "after make_heap, v: ";
	for (auto i : v) 
		cout << i << " ";
	cout << endl;

	std::pop_heap(v.begin(), v.end());
	cout << "after pop_heap, v: ";
	for (auto i : v) cout << i << " ";
	cout << endl;

	auto top = v.back();
	v.pop_back();
	cout << "former top element: " << top << endl;

	cout << "after removing the former top element, v: ";
	for (auto i : v)
		cout << i << " ";
	cout << endl;


	//===Min heap
	cout << "Min heap: " << endl;
	vector<int> v1 { 3, 2, 4, 1, 5, 9 };
	cout << "initially, v1: ";
	for (auto i : v1) 
		cout << i << " ";
	cout << endl;

	std:: make_heap(v1.begin(), v1.end(), std::greater<> {});
	cout << "after make_heap, v1: ";
	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	std::pop_heap(v1.begin(), v1.end());
	cout << "after pop_head, v1: ";
	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	auto top1 = v1.back();
	v1.pop_back();
	cout << "former top element: " << top1 << endl;

	cout << "after removing the former top element, v1: ";
	for (auto i : v1) cout << i << " ";
	cout << endl;

	return 0;
}

