
//main.cc
#include "class.hpp"


//ok
//Base Constructor
//Inherit Constructor!
//Base::print()
//Inherit Destructor!
//Base Destructor
void test_inherit_to_base()
{
	Base* pbase = new Inherit();

	pbase->print();

	delete pbase; //ok, delete inherit -> delete base
}

//ok
//Base Constructor
//Inherit Constructor!
//Inherit::show()
//Inherit Destructor!
//Base Destructor
void test_base_to_inherit()
{
	//Base *pbase = new Base(); //Error: will generate memory leak 
	Base *pbase = new Inherit(); //ok, 转换好并未丢失inherit数据

	Inherit *pInherit = dynamic_cast<Inherit*>(pbase);
	pInherit->show();

	delete pInherit;
}

//error: mem leak
//Base Constructor
//Inherit::show()
void test_base_to_inherit2()
{
	Base *pbase = new Base(); //Error: will generate memory leak 

	Inherit *pInherit = dynamic_cast<Inherit*>(pbase); //mem leak
	if (pInherit == NULL) {
		cout << "pInherit is NULL!" << endl;
	}

	Inherit *pInherit_s = static_cast<Inherit*>(pbase); //mem leak
	if (pInherit_s == NULL) {
		cout << "pInherit static is NULL!" << endl;
	} else {
		cout << "pInherit static is not NULL! not safe" << endl;
	}
	
	pInherit->show();

	delete pInherit;
}

//mem ok 
//Base Constructor
//Inherit::show()
//Base Destructor
void test_base_to_inherit3()
{
	Base *pbase = new Base(); //Error: will generate memory leak 

	Inherit *pInherit = (Inherit *)pbase;
	pInherit->show();

	delete pInherit;
}

int main()
{
	test_base_to_inherit2();
//	test_inherit_to_base();

	return 0;
}

