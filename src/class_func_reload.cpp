
//funtion  overload
#include <iostream> 

using namespace std;

class printData {
	public:
		void print(int i) {
			cout << "Interger:" << i << endl;
		}
		
		void print(double f) {
			cout << "Bouble:" << f << endl;
		}
		
		void print(string s) {
			cout << "String: " << s << endl;
		}
};

int main()
{
	printData p1;
	
	string s = "hello";
	p1.print(s);
	
	double d = 12.14;
	p1.print(d);
	
	int i = 10;
	p1.print(i);
	
	return 0;
}
