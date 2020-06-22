/* class constructor && desctructor */
#include <iostream>

using namespace std;

class Line {
	private :
		int *ptr;
	
	public:
		/* constructor */
		Line(int len);
		Line(const Line &old);
		
		/* destructor */
		~Line(void);
			
		void setLength(int len);
		int getLength();
};


Line::Line(int len)
{
   ptr = new int;
   *ptr = len;
}

Line::~Line()
{
	cout << "Destructor!" << endl;
	delete ptr;
}

Line::Line(const Line &old)
{
	ptr = new int;
	*ptr = *old.ptr;
}

void Line::setLength(int len)
{
	*ptr = len;
}

int Line::getLength()
{
	return *ptr;
}

int main()
{
	/* old obj */
	Line l(10);
	cout << "Line:" << l.getLength() << endl;
	
	/* copy construct1 */
	Line l2(l);
	cout << "Line2 :" << l2.getLength() << endl;
	
	/* copy construct2 */
	Line l3 = l2;
	cout << "Line3 :" << l3.getLength() << endl;
	
	return 0;
 } 
