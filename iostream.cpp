/* ifstream  && ofstream */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out("./o.txt");
	
	char buff[BUFSIZ] = {0};
	
	gets(buff);
	
	out << buff;
	
	return 0;
}
