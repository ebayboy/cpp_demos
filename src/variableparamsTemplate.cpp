//可变参数模板

#include<iostream>

using namespace std;

int add(int v)
{
    cout << "LINE:" << __LINE__ << " v:" << " v:" << v << endl;
    return v;
}

template<class T, class ... Types>
int add(T v, Types ... args)
{
    cout << "LINE:" << __LINE__ << endl;
    return add(args ...);
}

template<class ... Types>
int add(int v, Types ... args)
{
    cout << "LINE:" << __LINE__ << " v:" << v << endl;
    return v + add(args ...);
}

int main(int argc, char const *argv[])
{
    //int ret = add(1,2,3,4);
     int ret = add(1,2,"book", 3, 4);
    cout << "add: " << ret << endl;

    return 0;
}
