/* class static func */

/* 静态变量： 
们可以使用 static 关键字来把类成员定义为静态的。
当我们声明类的成员为静态时，
这意味着无论创建多少个类的对象，静态成员都只有一个副本。 */

/* 静态成员函数：
没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。*/

#include <iostream>

using namespace std;

class Box {
	private:
		double length;     // 长度
		double breadth;    // 宽度
		double height;     // 高度

	public:
		static int objCount;
		Box(double l=2.0, double b=3.0, double h=4.0) {
			length = l;
			breadth = b;
			height = h;

			/* 每次调用构造函数增加 1*/
			objCount++;
		}
		
		double Volume() {
			return length * breadth * height;
		}
		
		static int getObjCount(void)
		{
			return objCount;
		}
};

/* init static var */
int Box::objCount = 0;

int main() {
	Box b1(1.0, 2.0, 5.0);
	
	cout << "Box::objCount : " << Box::objCount << endl;
	
	Box b2;
	
	cout << "b1 volume :" << b1.Volume() << endl;
	cout << "b2 volume :" << b2.Volume() << endl;
	
	cout << "Box::objCount : " << Box::getObjCount() << endl;

	return 0;
}



