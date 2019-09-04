/* char array */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[11] = "hello";
	char str2[11] = "world";
	char str3[11];
	int len;
	
	strcpy(str3, str1);
	cout << "str3:" << str3 << endl;
	
	strcat(str1, str2);
	cout << "str1:" << str1 << endl;
	
	len = strlen(str1);
	cout << "len:" << len << endl;

	return 0;	
}
