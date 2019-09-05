/* class_protect.class */

/* 派生类对象转换成基类对象 */ 

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

	SmallBox *small = new SmallBox();
	
	/* 访问顺序  派生类public函数 -> 基类public成员 */ 
	small->setSmallWidth(5.0);
	cout << "SmallWidth:" << small->getSmallWidth() << endl;
	
	/* 访问顺序 派生类public函数 -> 基类public函数 -> 基类private成员  */ 
	small->setSmallHeight(11.01); 
	cout << "getSmallHeight:" << small->getSmallHeight() << endl;
	
	/* 派生类转换成基类 */ 
	Box *b = (Box *)small;
	
	cout << "Before convert , Box Height: " << b->getHeight() << endl;
	
	/* 基类设置height */ 
	b->setHeight(20.01);
	
	/* 结果都是 20.01 */ 
	cout << "After convert Box Height: " << b->getHeight() << endl;
	cout << "After convert SmallBox Height: " << small->getSmallHeight() << endl;

	return 0;
}

