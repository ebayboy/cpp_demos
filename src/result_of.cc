#include <iostream>
#include <functional>

#include <cmath>

using namespace std;
using namespace std::placeholders;

typedef double(*FUNC)(double);

double func(double d)
{
	return sin(d);

}

int main()
{
	result_of<FUNC(double)>::type d = func(9.0);

	cout << "d:" << d;

	return 0;

}
