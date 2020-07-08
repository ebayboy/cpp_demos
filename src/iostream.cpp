/* ifstream  && ofstream */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int age;
	cin >> age;
	cout << age <<endl;

	string name;
	cin >> name;
	cout << name << endl;

	cout.width(2);
	cout.fill('0');
	cout << age << endl;;

	return 0;
}
