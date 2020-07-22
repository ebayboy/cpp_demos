/*
    万能引用：
    C++ 11中有万能引用（Universal Reference）的概念：使用T&&类型的形参既能绑定右值，又能绑定左值。

    但是注意了：只有发生类型推导的时候，T&&才表示万能引用；否则，表示右值引用。
*/
#include <bits/stdc++.h>

using namespace std;

#if 0
void func(const int i &)
{
    cout << i << endl;
}

void func(int i&)
{
    cout << i << endl;
}

void func(int &&i)
{
    cout << i << endl;
}
#else
//万能引用代替上面的一堆函数
template <typename T>
void func(T &&i)
{
    cout << i << endl;
}

#endif

int main(int args, char **argv)
{
    int a = 1;
    const int b = a;

    func(b);  //调用 func(const int &i)
    func(a);  //调用 func(int &i)
    func(1);  //调用 func(int &&i)

    return 0;
}
