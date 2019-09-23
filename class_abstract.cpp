/* C++ 抽象类（接口） && 虚函数 */

#include <iostream>

using namespace std;

/* 抽象类：含有虚函数的类 */ 
class Box {
	protected:
		double length;
		double breadth;
		double height;

	public:
		Box(int l = 0, int b = 0, int h = 0) { 
			length = l;
			breadth = b;
			height = h;
		}
		
		/* 虚函数 */ 
		virtual double getVolume() = 0;
};

class TranbleBox : Box {
	public:
		TranbleBox(int l, int b, int h) : Box(l, b, h) { };
		double getVolume() {
			return length * breadth * height;
		}
};

int main() {
	TranbleBox t(1,2,3);
	
	cout << "Volume: " << t.getVolume() << endl;

	return 0;
}


