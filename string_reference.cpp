/* string refer 
	�ڴ��ݲ�����ʱ�����������string���ͣ�������string���͵����ã������ڴ�Ŀ�����
*/

#include <iostream>
#include <cstring>

using namespace std;

void func(const std::string& str){
	cout << "str = " << str << endl;
	cout << "address of \"str\" : " << &str << endl; 
}

void funcB(const std::string str){
	cout << "str = " << str << endl;
	cout << "address of \"str\" : " << &str << endl;
}


int main(int agrc, char** argv){
	string strInMain= "test";
	
	func(strInMain);
	funcB(strInMain);
	
	cout << "strInMain = " << strInMain << endl;
	cout << "address of \"strInMain\" : " << &strInMain << endl;
	
	return 0;
}

