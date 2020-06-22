/* class_protect.class */

#include <iostream>
#include <cstring>

using namespace std;

/* ================  CLASS BOX ================== */
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

/* ================== CLASS SMALLBOX =========================== */
class SmallBox : Box
{
	public:
		void setSmallWidth(double wid);
		double getSmallWidth(void);	
		void setSmallHeight(double h);
		double getSmallHeight(void);
};

double SmallBox::getSmallWidth()
{
	return width;
}

void SmallBox::setSmallWidth(double wid)
{
	//set box protected width
	width = wid;
}

void SmallBox::setSmallHeight(double h)
{
	setHeight(h);
}
double SmallBox::getSmallHeight(void)
{
	return getHeight();
}

/* ==========================  MAIN ======================= */
int main()
{

	SmallBox small;
	
	small.setSmallWidth(5.0);
	cout << "SmallWidth:" << small.getSmallWidth() << endl;
	
	/* ����˳�� ������public���� -> ����public���� -> ����private��Ա  */ 
	small.setSmallHeight(11.01); 
	cout << "getSmallHeight:" << small.getSmallHeight() << endl;
	
	/* ������� */ 
	Box box;
	box.setHeight(15.01);
	cout << "Box height:" << box.getHeight() << endl;

	return 0;
}

