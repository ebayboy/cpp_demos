#include <iostream>

using namespace std;

class Box
{
	private:
		double height;
		
	protected: 
		double width;	
	
	public:
		void setHeight(double h);
		double getHeight(void);
};

void Box::setHeight(double h)
{
	height = h;
}
double Box::getHeight(void)
{
	return height;
}

class SmallBox:Box
{
	public:
		void setSmallWidth(double wid);
		double getSmallWidth(void);	
};

double SmallBox::getSmallWidth()
{
	return width;
}

void SmallBox::setSmallWidth(double wid)
{
	width = wid;
}

int main()
{
	Box b;
	
	b.setHeight(15.01);
	cout << "Box height:" << b.getHeight() << endl;
	
	SmallBox s;
	s.setSmallWidth(10.01);
	cout << "SmallBox width: " << s.getSmallWidth() << endl;
	
	return 0;
}

