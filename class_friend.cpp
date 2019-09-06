/* class friend func */

#include <iostream>

using namespace std;

class Box
{
	
private:
	double width;
	
public:
	void setWidth(double wid);
	
	friend void printWidth(Box box); /* friend func */
};

void Box::setWidth(double w)
{
	this->width = w;
}

/* friend func */
void printWidth(Box box)
{
	cout << "Width:" << box.width << endl;
}

int main()
{
	Box b;
	b.setWidth(20.01);
	
	printWidth(b);
	
	return 0;
}
