/* class this pointer */

#include <iostream>


using namespace std;

class Box
{
	private:
		double length;
		double breadth;
		double height;
		
	public:
		Box(double l=2.0, double b=3.0, double h=4.0)
		{
			length = l;
			breadth = b;
			height = h;
		}	
		
		double Volume()
		{
			return length * breadth * height;
		}
		
		int compare(Box box) 
		{
			return this->Volume() > box.Volume();
		}
};

int main()
{
	Box b1(1, 2, 3);
	//Box b2(3, 4, 5);
	Box b2;
	
	cout << "b1->Volume:" << b1.Volume() << endl;
	cout << "b2->Volume:" << b2.Volume() << endl;
	
	if (b1.compare(b2)) {
		cout << "b1 > b2" << endl;
	} else {
		cout << "b1 <= b2" << endl;
	}
	
	return 0;
}
