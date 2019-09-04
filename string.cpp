/* string */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "hello";
	string str2 = "world";
	string str3;
	int len;
	
	str3 = str1;
	cout << "str3:" << str3 << endl;
	
	str3 = str1 + str3;
	cout << "str3:" << str3 << endl;
	
	len = str3.size();
	cout << "len:" << len << endl;
	
	return 0;
}
