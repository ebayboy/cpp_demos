//1. clock_t -- get timestatmp

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG

void test1()
{
    int a=2, b=3;
    cout << "initial, a,b:" << a  << " " << b << endl;
    cout << "max(2,3): " << max(a,b) << endl;

    swap(a, b);
    cout << "a:" << a << endl;;
    cout << "b:" << b << endl;;
}

int main(int argc, char **argv)
{
    clock_t start, end;

    start = clock();

	test1();

    end = clock();

    cout << "func test1 use time: " << end - start << "(ms)" << endl;

    return 0;
}

