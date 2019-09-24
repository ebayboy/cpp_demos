/* new_del */

#define _CRTDBG_MAP_ALLC

#include <iostream>
#include <crtdbg.h>

using namespace std;

int main() {


	double *pvalue = NULL;
	pvalue = new double;

	_CrtDumpMemoryLeaks();

	*pvalue = 3.1415196;

	cout << "pvalue: " << *pvalue << endl;

	system("pause");
	//delete pvalue;

	return 0;
}
