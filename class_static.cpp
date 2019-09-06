/* class static func */

/* ��̬������ 
�ǿ���ʹ�� static �ؼ����������Ա����Ϊ��̬�ġ�
������������ĳ�ԱΪ��̬ʱ��
����ζ�����۴������ٸ���Ķ��󣬾�̬��Ա��ֻ��һ�������� */

/* ��̬��Ա������
û�� this ָ�룬ֻ�ܷ��ʾ�̬��Ա��������̬��Ա�����;�̬��Ա��������*/

#include <iostream>

using namespace std;

class Box {
	private:
		double length;     // ����
		double breadth;    // ���
		double height;     // �߶�

	public:
		static int objCount;
		Box(double l=2.0, double b=3.0, double h=4.0) {
			length = l;
			breadth = b;
			height = h;

			/* ÿ�ε��ù��캯������ 1*/
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



