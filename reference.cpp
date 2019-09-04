/* reference: reference is another name of variable */

#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int c = 30;
	int &b = a;
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	/* update origion value a */
	cout << "update origion value a:" << endl;
	a = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	/* update referrence value */
	cout << "update referrence value a:" << endl;
	b = 15;
	cout << "a=" << a << endl;
	
	/* update reference b */
	cout << "update reference b -> c:" << endl;
	b = c;
	cout << "b=" << b << endl;
	
	return 0;
}
