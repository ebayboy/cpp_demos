/****************************************************************************
@file:dequeue.cpp 
@author:ebayboy@163.com 
@date:2019-10-14 11:15 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <deque>

using namespace std;

void show_deque(deque <int> d)
{
	for (deque<int>::iterator it=d.begin(); 
			it != d.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
}

void show_deque2(deque <int> d)
{
	cout << __func__ << ":" << __LINE__ << endl;
	for (size_t i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}

	cout << endl;
}

int main(int argc, char **argv)
{
	deque <int> d;

	/* push back */
	for (int i = 0; i <=5; i++) {
		d.push_back(i);
	}
	cout << endl << "push back:" << endl;
	show_deque(d);

	/* push front */
	d.push_front(6);
	d.push_front(7);
	cout << endl << "push front" << endl;
	show_deque(d);

	/* pop front */
	d.pop_front();
	cout << endl << "pop front:" << endl;
	show_deque(d);

	/* pop back */
	d.pop_back();
	cout << endl << "pop back:" << endl;
	show_deque(d);

	/* insert at pos */
	d.insert(d.begin()+ 1, 100);
	cout << endl << "insert at pos d.begin()+ 1):" << endl;
	show_deque(d);

	/* del at pos d.end() - 2 )*/
	d.erase(d.end() - 2);
	cout << endl << "del at pos - 2" << endl;
	show_deque(d);

	cout << "size:" << d.size() << endl;

	cout << "resize -> 2:" << endl;
	d.resize(2);
	show_deque(d);
	
	cout << "clear all:" << endl;
	d.clear();
	show_deque(d);

	return 0;
}

