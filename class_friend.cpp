/* class friend func */

#include <iostream>

using namespace std;

//友元函数： 定义在类的外部， 但有权访问类的私有成员和保护成员

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
