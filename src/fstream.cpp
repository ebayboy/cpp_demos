/* fstream.cpp */

#include <fstream>
#include <iostream>

using namespace std;

int main() 
{
	fstream f;
	
	/* 写文件 */ 
	f.open("1.txt", ios::out | ios::in | ios::app);
	if (f.bad()) {
		cout << "open error!" << endl;
	}
	f << "hello" << endl; 
	
	/* 读文件:将文件指针移动到头， 读取一行内容  */ 
	f.seekg(0,ios::beg);  
	char data[1024] = {0};
	f >> data;
	
	cout << "read" << data << endl;
	f.close();
		
	return 0;
}
