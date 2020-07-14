/* fstream.cpp */

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void readfile(string fname)
{
	std::ifstream t;
	int length;
	t.open(fname);				 // open input file
	t.seekg(0, std::ios::end);		 // go to the end
	length = t.tellg();				 // report location (this is the length)
	t.seekg(0, std::ios::beg);		 // go back to the beginning
	char *buffer = new char[length]; // allocate memory for a buffer of appropriate dimension
	t.read(buffer, length);			 // read the whole file into the buffer
	t.close();						 // close file handle
}

void readfile2(string fname)
{
	std::ifstream t(fname);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string contents(buffer.str());
}

int main()
{
	fstream f;

	/* д�ļ� */
	f.open("1.txt", ios::out | ios::in | ios::app);
	if (f.bad())
	{
		cout << "open error!" << endl;
	}
	f << "hello" << endl;

	/* ���ļ�:���ļ�ָ���ƶ���ͷ�� ��ȡһ������  */
	f.seekg(0, ios::beg);
	char data[1024] = {0};
	f >> data;

	cout << "read" << data << endl;
	f.close();

	return 0;
}
