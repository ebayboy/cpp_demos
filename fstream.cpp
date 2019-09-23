/* fstream.cpp */

#include <fstream>
#include <iostream>

using namespace std;

int main() 
{
	fstream f;
	
	/* д�ļ� */ 
	f.open("1.txt", ios::out | ios::in | ios::app);
	if (f.bad()) {
		cout << "open error!" << endl;
	}
	f << "hello" << endl; 
	
	/* ���ļ�:���ļ�ָ���ƶ���ͷ�� ��ȡһ������  */ 
	f.seekg(0,ios::beg);  
	char data[1024] = {0};
	f >> data;
	
	cout << "read" << data << endl;
	f.close();
		
	return 0;
}
