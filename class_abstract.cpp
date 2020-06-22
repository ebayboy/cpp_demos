#include <iostream>

using namespace std;

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
		
		//纯虚函数，等于0表示没有函数体
		virtual double getVolume() = 0;
};

class TranbleBox : Box {
	public:
		//虚函数： 实现了纯虚函数
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


