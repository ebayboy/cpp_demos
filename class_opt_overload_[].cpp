/* class_opt_overload_[].class */

#include <iostream>

using namespace std;

const int SIZE = 10;

class safearray {
	private:
		int arr[SIZE];
	
	public:
		safearray() {
			int i;
			for (i = 0; i < SIZE; i++) {
				arr[i] = i;
			}
		}
		
		int& operator[](int i) {
			if (i >= SIZE) {
				cout << "Error: too max index!" << endl;
				return arr[0];
			}
			
			return arr[i];
		}
		
};

int main()
{
	safearray a;
	
	cout << "a[0]:" << a[0] << endl;
	cout << "a[5]:" << a[5] << endl;
	cout << "a[11]:" << a[11] << endl;
	
	return 0;
}
