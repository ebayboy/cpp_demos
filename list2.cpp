/****************************************************************************
@file:list2.cpp 
@author:ebayboy@163.com 
@date:2019-10-14 16:08 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

#define DEBUG 

void showlist(list<int> l, string title)
{
	list<int>::iterator i;

	cout << title << ": " << endl;
	for (i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}

	cout << endl << endl;

}

int main(int argc, char **argv)
{

	cout<<"hello world!"<<endl;

	list<int> l1;

	list<int> l2(10, 6);

	list<int> l3(l2.begin(),--l2.end());

	cout << "show l1:" << endl;
	showlist(l1, "l1");

	cout << "show l2:" << endl;
	showlist(l2, "l2");

	cout << "show l3:" << endl;
	showlist(l3, "l3");


	//1, 2
	l1.push_back(1);
	l1.push_back(2);
	showlist(l1, "l1");

	//7, 5, 1, 2
	l1.push_front(5);
	l1.push_front(7);
	showlist(l1, "l1");

	//list 7 5  1 2  -> 5 1 2 -> 5 1
	l1.pop_front();
	l1.pop_back();
	showlist(l1, "l1");

#if 0
	// 5 1 -> 1
	l1.erase(l1.begin());
	showlist(l1, "l1");
#else
	// 5 1 -> 5
	l1.erase(++l1.begin());
	showlist(l1, "l1");
#endif

	cout << "new l2: " << endl;
	//重置l2的内容
	l2.assign(8, 1);
	showlist(l2, "l2");

	cout << "l1.max_size: " << l1.max_size() << endl;
	cout << "l1.size: " << l1.size() << endl;
	//check list is empty
	cout << "l1.empty: " << l1.empty() << endl;

	l1.push_back(7);
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(2);
	showlist(l1, "l1");

	l1.sort();
	showlist(l1, "l1 sort");

	showlist(l1, "l1");
	showlist(l3, "l3");

	l1.splice(l1.end(), l3);
	showlist(l1, "l1");
	showlist(l3, "l3");

	return 0;
}

