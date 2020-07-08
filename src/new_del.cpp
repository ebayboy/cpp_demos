/* new_del */

#include <iostream>

using namespace std;

int main() {

	double *pvalue = NULL;
	pvalue = new double;

	*pvalue = 3.1415196;

	cout << "pvalue: " << *pvalue << endl;

	delete pvalue;

	return 0;
}
