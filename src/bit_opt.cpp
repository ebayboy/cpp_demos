
/* bit opt */

#include <iostream>

using namespace std;

int main()
{
	unsigned short a = 0x3c;
	unsigned short b = 0xd;
	
	unsigned short c = a & b;
	
	cout << "a & b = 0x" << hex << c << endl;
	
	cout << "c=0x" << hex << a << endl;
	
	return 0;
}
