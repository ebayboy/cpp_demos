/* reference 2 */

#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main()
{
	int a = 100;
	int b = 200;
	
	cout << "before swap a, b " << a << ", "<< b <<endl;
	
	swap(a,b);
	cout << "after swap a,b " << a <<", "<< b << endl;
	
	return 0;
}

void swap(int &a, int &b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}
