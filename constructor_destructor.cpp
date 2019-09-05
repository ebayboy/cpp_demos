/* class constructor && desctructor */

#include <iostream>

using namespace std;

class Line {
	private :
		int length;
		int points;
	
	public:
		/* constructor */
		Line(int len, int pns);
		
		/* destructor */
		~Line(void);
			
		void setLength(int len);
		int getLength();
		
		void setPoints(int len);
		int getPoints();
};

#if 1
Line::Line(int len,int pns)
{
	cout << "constrctor" << endl;
	
	this->length = len;
	this->points = pns;
}
#else
Line::Line(int len, int pns) : length(len), points(pns)
{
   
}
#endif

Line::~Line()
{
	cout << "Destructor!" << endl;
}

void Line::setLength(int len)
{
	length = len;
}

int Line::getLength()
{
	return length;
}

void Line::setPoints(int p)
{
	points = p;
}

int Line::getPoints()
{
	return points;
}

int main()
{
	Line l(10,11);
	cout << "length: " << l.getLength() << endl;
	cout << "points: " << l.getPoints() << endl;
	
	cout << endl << "after set methods" << endl;
	
	l.setLength(20);
	l.setPoints(21);
	cout << "length: " << l.getLength() << endl;
	cout << "points: " << l.getPoints() << endl;
	
	return 0;
 } 
