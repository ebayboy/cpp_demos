
/*
unsinged short���͵�ȡֵ��Χ��: 0 ~ 65535 
short���͵�ȡֵ��Χ��:-32768---32767 
*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	unsigned short u = 65535;
	short s = u;
	
	cout << "unsigned " << u << endl;
	cout << "signed "<< s << endl;
	
	return 0;
}
