//Class.h
#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>

using namespace std;

class Base
{
	private:
		char *m_base;

	public:
		Base() 
		{
			cout << ("Base Constructor") << endl;
			m_base = new char[10];
		}

		virtual ~Base() 
		{
			delete [] m_base;
			cout << "Base Destructor" << endl;
		}

		void print() {
			cout << "Base::print()" << endl;
		}
};

class Inherit :public Base
{
	private:
		char *m_inherit;

	public:
		Inherit() {
			cout << "Inherit Constructor!" << endl;
			m_inherit = new char[20]; //base not virtual, will mem leak
		}

		~Inherit() {
			if (m_inherit){
				delete [] m_inherit;
			}
			cout << "Inherit Destructor!" << endl;
		}

		void show() {
			cout << "Inherit::show()" << endl;
		}
};
#endif


