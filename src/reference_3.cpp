/* reference_3.cpp */

#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

/* return val[i] reference */
double & setValues(int i)
{
	return vals[i];
}

int main()
{
	cout << "before change:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "vals[" << i << "] =";
		cout << vals[i] << endl;
	}
	
	setValues(1) = 20.23;
	setValues(3) = 70.83;
	
	cout << "after change:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "vals[" << i << "] = ";
		cout << vals[i] << endl;
	}
	
	return 0;
}
