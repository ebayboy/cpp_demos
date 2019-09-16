/* class_opt_cin_out overload */

#include <iostream>

using namespace std;

class Distance {
	private:
		int feets;
		int inches;
		
	public:
		Distance() {
			this->feets = 0;
			this->inches = 0;
		}
		
		Distance(int f, int i) {
			this->feets = f;
			this->inches = i;
		}
		
		friend ostream &operator<< (ostream &output, const Distance &D) {
			output << "F:" << D.feets << " I: " << D.inches;
			return output;
		}
		
		friend istream &operator>>(istream &input, Distance &D) {
			input >> D.feets >> D.inches;
			return input;
		}
		
		/* 前置++ */ 
		Distance operator++() {
			++this->feets;
			++this->inches;
			
			return *this;
		}
		
		/* 后置 ++ */ 
		Distance operator++(int) {
			Distance tmp = *this;
			++this->inches;
			++this->feets;
			
			return tmp;
		}
		
		/* 一元操作符： >  */ 
		bool operator>(Distance &c) {
			if (this->feets > c.feets) {
				return true;
			}
			
			return false;
		}
};

int main() {
	Distance D1(11, 10);
	Distance D2(5,11);
	Distance D3;
	
	cin >> D3;
	
	cout << "D1:" << D1 << endl;
	cout << "D2:" << D2 << endl;
	cout << "D3:" << D3 << endl; 
	
	cout << "D1++: " << ++D1 <<endl;
	cout << "++D2: " << D2++ <<endl;
	cout << "D2:" << D2 << endl;
	
	cout <<"D2 > D1 ? " << (D2 > D1) << endl; 
	
	return 0;
} 
