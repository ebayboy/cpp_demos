/* pointer */

#include <iostream>

using namespace std;


int main()
{
	int var1 = 20;
	char var2[10] = {0};
	
	int *p1 = &var1;
	
	cout << "var1 addr:" << &var1 << endl;
	cout << "var2 addr:" << &var2 << endl;
	cout << "var1:" << var1 << endl;
	cout << "p1:" << p1 << endl;
	cout << "p1 value:" << *p1 << endl;
	cout << "p1 addr:" << &p1 << endl;
	
	return 0;
}
