
#include <iostream>


using namespace std;

class Box 
{
	public :
		Box() {
			cout << "Constructor!" << endl;
		}
		~Box() {
			cout << "Destructor!" << endl;
		}

};

int main()
{
	Box *bArr = new Box[4];

	delete [] bArr;

	return 0;
}
