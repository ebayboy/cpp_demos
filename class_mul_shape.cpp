/* 类多态 : class_mul_shape.cpp 
   多态： 就是派生类继承基类后， 不同的派生类对基类的方法有多种实现形态 
*/

#include <iostream>

using namespace std;

/* base shape */
class Shape {
	
	/* protected 可以被派生类直接访问 */ 
	protected:
		int  width;
		int height;
	
	public:
		Shape(int a=0, int b = 0) {
			width = a;
			height = b;
		}
		
		/* 虚函数 */ 
		virtual int area() = 0;		
};

class Rectangle: public Shape {
	public:
		
		/* 派生类构造函数继承基类构造函数 */ 
		Rectangle (int a=0, int b = 0) : Shape(a, b) { }
		int area ()
		{
			cout << "Rectangle class area:" << endl;
			return (width * height);	
		}
};

class Triangle : public Shape {
	public:
		Triangle (int a=0, int b= 0) : Shape(a, b) { }
		int area() {
			cout << "Triangle class area: " << endl;
			return (width * height/2);
		}
		 
};

int main()
{
	Rectangle r(5, 10);
	Triangle t(5, 10);
	
	/* 带虚函数的基类不能被实例化 */ 
	// Shape s(1, 5);
	
	cout << r.area() << endl;
	cout << t.area() << endl;
	
	return 0;
} 
 
 


