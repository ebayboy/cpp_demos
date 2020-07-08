/*ifstream.cpp */


#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream file;
	char data[1024]  = {0};
	
	/* open */
	file.open("file.dat", ios::out | ios::in);
	if (file.bad()) {
		return -1;
	}
	
	/* write */
	cin >> data;
	cout << "data:" << data << endl;
	file << data << endl;
	
	/* read */
	file >> data; 
	
	cout << "data read:" << data << endl;
	
	/* close */
	file.close();
		
	return 0;
}
