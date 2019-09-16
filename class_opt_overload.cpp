/* class  运算符重载 */

#include <iostream>

using namespace std;

class Box {
	private:
		int length;

	public:
		Box(int l=10);
		int getLength();
		void setLength(int x);
		
		/* 一元操作重载 */ 
		Box operator+(const Box &b);
		bool operator<(const Box &b);
		
		/* 自增运算符 */ 
		Box operator++ ();
		Box operator++ (int);
		
		/* 友缘 输入/输出运算符 */ 
		friend ostream &operator << (ostream &output, const Box &b) {
			output << "Length:" << b.length << endl;
			return output;
		}
		friend istream &operator >> (istream &input, Box b) {
			input >> b.length;
			return input;
		}
};

/* contructor */
Box::Box(int l) {
	length = l;
}

/* 一元操作符: operator+ */
Box Box::operator+(const Box &b) {
	Box box;

	box.length = this->length + b.length;

	return box;
}

/* 一元操作符:  operation < */
bool Box::operator<(const Box &b) {
	if (this->length < b.length) {
		return true;
	}

	return false;
}

/* 重载前缀++ */
Box Box::operator++ () {
	++this->length;
	return *this;
}

/* 重载后缀++ */
Box Box::operator++ (int) {
	Box temp = *this;

	this->length++;

	return temp;
}

int Box::getLength() {
	return length;
}

void Box::setLength(int l) {
	length = l;
}

int main() {
	Box a; /* 10 default */

	Box b(20);

	Box c;
	c.setLength(30);  /* set to 30 */

	Box t = a + b + c;  /* should be 60 */

	cout << "a + b :" << t.getLength() << endl;

	cout << "a < b ? " << (c < b) << endl;

	cout << a << endl;
	
	cout << b << endl;
	
	cout << "before++" << a++ << endl;
	cout << "after" << a << endl;
	
	cout << "++before" << ++a << endl;
	cout << "after" << a << endl;
	
	return 0;
}
