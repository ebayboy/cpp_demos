/* file read && write */

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

/* write to file */
int txt_write(const char* fname, string data)
{
	/* ios:app 文件不存在则创建， 在末尾写入 */ 
	fstream f(fname, ios::out | ios::app);
	if (f.bad()) {
		return -1;		
	}
	
	f << data;
	
	f.close();
	
	return 0;
}

/* read file all */
int txt_read(const char *fname, string &data)
{
	std::stringstream buffer;  
	
	fstream f(fname, ios::in);
	
	if (f.bad()) {
		return -1;
	}

	buffer << f.rdbuf();	
	data = buffer.str();

	f.close();
	
	return 0;
}

int write_bin(const char *fname, char *data, int dlen)
{
	fstream f(fname, ios::out | ios::binary | ios::app);
	if (f.bad()) {
		return -1;
	}
	f.write(data, dlen);
	f.close();
	
	return 0;
}

int read_bin(const char *fname, char *data, int dlen)
{
	fstream f(fname, ios::in | ios::binary);
	if (f.bad()) {
		return -1;
	}
	f.read(data, dlen);
	f.close();
	
	return 0;
}

int main()
{
	/* write file */
	string wdata = "hello world11!\n";
	txt_write("txt_write.txt", wdata);
	
	/* read file */
	string rdata;
	txt_read("txt_write.txt", rdata);
	cout << "rdata:" << rdata << endl;
	
		/* write bin file */
	string wbdata = "hello world11!\n";
	txt_write("bin_write.bin", wbdata);
	
	/* read file */
	string rbdata;
	txt_read("bin_write.bin", rbdata);
	cout << "rbdata:" << rbdata << endl;
	
	return 0;
}
