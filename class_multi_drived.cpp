/* class multi driverd */

#include <iostream>

using namespace std;

/* base1 */
class Shape {
	protected:
		int width;
		int height;
		
	public:
		void setWidth(int w) {
			width = w;
		}
		void setHeight(int h) {
			height = h;
		}
};

/* base2 */
class PaintCost {
	public:
	int getCost(int area) {
		return area * 70;
	}
};

class Rectangle : public Shape, public PaintCost {
	public :
		int getArea() {
			return (width * height);
		}
};


int main()
{
	Rectangle Rect;
	int area;
	
	/* use base1 set function */
	Rect.setWidth(5);
	Rect.setHeight(7);
	
	/* use own getArea */
	area = Rect.getArea();
	cout << "Total area: " << area << endl;
	
	/* use base2 getCost */
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;
	
	return 0;
}
