/****************************************************************************
@file:map.cpp 
@author:ebayboy@163.com 
@date:2019-10-08 15:22 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	map<string, string> dic;
	map <string,string>::iterator it;

	dic.insert(pair<string,string>("id1", "value1"));
	dic.insert(pair<string,string>("id2", "value2"));
	dic.insert(pair<string,string>("id3", "value3"));

	dic.insert(pair<string,string>("id1", "value11"));
	dic.insert(pair<string,string>("id3", "value33"));

	/* 遍历map */
	for (it = dic.begin(); it != dic.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}

	// find 
	it = dic.find("id1");

	if (it == dic.end()) {
		cout << "not find!" << endl;
	} else {
		cout << "value:" << dic["id1"] << endl;
	}


	//delete
	dic.erase(it); 
	cout << "after erase" << endl;
	if (it == dic.end()) {
		cout << "not find!" << endl;
	} else {
		cout << "value:" << dic["id1"] << endl;
	}

	return 0;
}

