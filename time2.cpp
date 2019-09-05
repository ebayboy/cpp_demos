/* time2 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

string get_time(void)
{
	char buff[64] = {0};
	
	time_t now = time(NULL);
	tm *ltm = localtime(&now);

	/* 2017-08-30 10:36:15 */	
	snprintf(buff, sizeof(buff), "%04d-%02d-%02d %02d:%02d:%02d", 
			1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,  
			ltm->tm_hour,ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
	return buff;
}

string get_time2(void)
{
	time_t now = time(NULL);
	char buff[64];
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S",localtime(&now) );
	return buff;
}

int main()
{
	string str = get_time();
	
	cout << "get_time:" << str << endl;	
	
	string time2 = get_time2();
	cout << "get_time2:" << time2 << endl;
	
	return 0;
}
