
//main.cc
#include "class.hpp"


void test_inherit_to_base()
{
	Base* pbase = new Inherit();

	pbase->print();

	delete pbase; //ok, delete inherit -> delete base
}

void test_base_to_inherit()
{
	//Base *pbase = new Base(); //Error: will generate memory leak 
	Base *pbase = new Inherit(); //ok, 转换好并未丢失inherit数据

	Inherit *pInherit = dynamic_cast<Inherit*>(pbase);
	pInherit->show();

	delete pInherit;
}

int main()
{
	test_base_to_inherit();

	return 0;
}

