/* class_1 */

#include <iostream>
#include <cstring>

using namespace std;

class Box {
	private:
	double volume;
	
	public:
	double length;
	double breadth;
	double height;
	
	void computeVolume()
	{
		this->volume = this->breadth * this->height * this->length;
	}
	
	double getVolume()
	{
		return this->volume;
	}
};

int main()
{
	Box Box1;
	Box Box2;
	
	double volume = 0.0;
	
	Box1.height = 5.0;
	Box1.breadth = 6.0;
	Box1.length = 7.0;
	
	Box2.height = 10.0;
	Box2.length = 12.0;
	Box2.breadth = 13.0;
	
	Box1.computeVolume();
	cout << "Box1 的体积:" << Box1.getVolume() << endl;
	
	Box2.computeVolume();
	cout << "Box2 的体积：" << Box2.getVolume() << endl;
	
	return 0;
}
