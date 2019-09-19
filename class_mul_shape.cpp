/* ���̬ : class_mul_shape.cpp 
   ��̬�� ����������̳л���� ��ͬ��������Ի���ķ����ж���ʵ����̬ 
*/

#include <iostream>

using namespace std;

/* base shape */
class Shape {
	
	/* protected ���Ա�������ֱ�ӷ��� */ 
	protected:
		int  width;
		int height;
	
	public:
		Shape(int a=0, int b = 0) {
			width = a;
			height = b;
		}
		
		/* �麯�� */ 
		virtual int area() = 0;		
};

class Rectangle: public Shape {
	public:
		
		/* �����๹�캯���̳л��๹�캯�� */ 
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
	
	/* ���麯���Ļ��಻�ܱ�ʵ���� */ 
	// Shape s(1, 5);
	
	cout << r.area() << endl;
	cout << t.area() << endl;
	
	return 0;
} 
 
 


