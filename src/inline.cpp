/* cpp inline func */
/* 编译器会把该函数的代码副本放置在每个调用该函数的地方 */


#include <iostream>

using namespace std;

inline int Max(int x, int y)
{
	return (x > y) ? x : y;
}


int main()
{
	cout << "Max(20, 10):" << Max(20, 10) << endl;
	cout << "Max(0, 200):" << Max(0, 200) << endl;
	cout << "Max(100, 1010)" << Max(100, 1010) << endl;
	
	return 0;
}
