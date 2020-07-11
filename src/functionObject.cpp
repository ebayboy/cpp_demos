/*
    function object : 函数对象就是一个重载了“()”运算符的类的对象，它可以像一个函数一样使用
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class myAdd
{
public:
    //对象重载了()操作符
    int operator()(int a, int b) { return a + b; }
};

int main(int args, char **argv)
{

    int a = 5, b = 10;

    myAdd myadd;
    int c = myadd(a, b);

    cout << "myAdd(a,b):" << c << endl;

    return 0;
}
