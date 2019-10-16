/****************************************************************************
@file:multimap.cpp 
@author:ebayboy@163.com 
@date:2019-10-16 13:08 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define DEBUG 


void mmap_show(multimap<string, string> m)
{
	multimap<string, string>::iterator it;

	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

	cout << endl;
}

int main(int argc, char **argv)
{
	multimap<string, string> m;

	//add
	m.insert(pair<string, string>("key1", "value1"));
	m.insert(pair<string, string>("key2", "value2"));
	m.insert(pair<string, string>("key3", "value3"));
	m.insert(pair<string, string>("key4", "value4"));
	m.insert(pair<string, string>("key4", "value4"));

	mmap_show(m);

	//erase all key4
	m.erase("key4");
	mmap_show(m);

	//find
	multimap<string, string>::iterator it;
	// just delete only one key4
	it = m.find("key4");
	if (it != m.end()){
		m.erase(it);
		cout << it->first << ":" << it->second << endl;
	} else {
		cout << "not find key4!" << endl;
	}
	mmap_show(m);

	return 0;
}

