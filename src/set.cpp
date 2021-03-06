/****************************************************************************
@file:set.cpp
@author:ebayboy@163.com
@date:2019-10-16 11:40
@version: 1.0
@description: cpp file
@Copyright (c)  all right reserved

//set: 不能插入重复元素

**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define DEBUG

void set_show(set<int> s, string info)
{
	cout << __func__ << info << endl;

	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	
	cout << endl;
}

void set_showr(set<int> s)
{
	set<int>::reverse_iterator ri;

	for (ri = s.rbegin(); ri != s.rend(); ri++) {
		cout << *ri << " ";
	}

	cout << endl;
}

int main(int argc, char **argv)
{
    set<int> s;

    for(int i = 0; i <5; i++)
    {
		s.insert(i);
    }

	set_show(s, "set s:");
	set_showr(s);

	//删除元素
	s.erase(2);
	set_show(s, "after earase 2, s:");

	set<int>::iterator it;
	it = s.find(3);
	if (it != s.end()) {
		cout << "find it: " << *it << endl;
	}

	cout << "size: " << s.size() << endl;
	cout << "max_size: " << s.max_size() << endl;

	s.clear();
	if (s.empty()) {
		cout << "s is empty!" << endl;
	}

    return 0;
}

