#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* extern */
extern int a, b;
extern int c;
extern float f;

/* extern func */
extern int func(int a, int b);

/* define func */
int func(int a, int b)
{
	return a * b;
}


int main(int argc, char** argv) {
	/* define */
	int a, b;
	int c;
	float f;
	
	a = 10;
	b = 20;
	c = a + b;
	
	cout << "c=" << c << endl;
	f = 70.01/3.0;
	
	cout << "f=" << f << endl;
	
	cout << "a*b=" << func(a,b) << endl;
	
	return 0;
}
