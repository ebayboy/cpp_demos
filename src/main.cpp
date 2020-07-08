#include <iostream>

using namespace std;

int g = 50;

int add(int a, int b)
{
	return a + b;
}

int main(int argc, char **argv)
{
	int g = 10;
	int a = 20;
	
	cout << add(a, g) << endl;
	
	return 0;
}
