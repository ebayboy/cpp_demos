/* extern_main.cpp */

#include <iostream>
#include "extern_child.cpp"

using namespace std;

int count = 5;

/* use extern_child function */
extern void write_extern(void);

int main()
{
	count = 5;
	write_extern();
	
	return 0;
}
