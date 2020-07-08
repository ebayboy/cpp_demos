/* cin && cout */

#include <iostream>

using namespace std;


int main()
{
	string name;
	int age;
	
	cout << "input your name:" << endl;
	cin >> name;
	cout << "your name is:" << name;
	
	cout << "input age:" << endl;
	do {
		cerr << "age error [1-100]" << age << endl;
		cin >> age;
	} while (age < 0 || age > 100);
	
	cout << "age: " << age << endl;
	

	
	return 0;
}
