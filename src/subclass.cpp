/* class_protect.class */

/* ���������ת���ɻ������ */

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
	Box()
	{
		cout << "Box constructor..." << endl;
	}
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
	SmallBox()
	{
		cout << "SmallBox constructor..." << endl;
	}
	SmallBox(string name)
	{
		cout << "SmallBox constructor..." << name << endl;
	}
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

#if 0
	SmallBox *small = new SmallBox();

	/* ����˳��  ������public���� -> ����public��Ա */
	small->setSmallWidth(5.0);
	cout << "SmallWidth:" << small->getSmallWidth() << endl;

	/* ����˳�� ������public���� -> ����public���� -> ����private��Ա  */
	small->setSmallHeight(11.01);
	cout << "getSmallHeight:" << small->getSmallHeight() << endl;

	/* ������ת���ɻ��� */
	Box *b = (Box *)small;

	cout << "Before convert , Box Height: " << b->getHeight() << endl;

	/* ��������height */
	b->setHeight(20.01);

	/* ������� 20.01 */
	cout << "After convert Box Height: " << b->getHeight() << endl;
	cout << "After convert SmallBox Height: " << small->getSmallHeight() << endl;
#endif
	//SmallBox sb;

	SmallBox sb1("fanpf");

	return 0;
}
