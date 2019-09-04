/* extern_child.cpp */

#include <iostream>

using namespace std;

/* use extern_main defined count */
extern int count;

void write_extern(void)
{
	cout << "Count is " << count << endl;
}
