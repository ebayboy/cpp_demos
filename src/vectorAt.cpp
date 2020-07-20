/*
    vector通过at访问和通过索引访问的问题（推荐通过at访问，异常程序不至于崩溃）
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int args, char **argv)
{
    vector<int> v(10);

    for (size_t i = 0; i < 10; i++)
    {
        v.at(i) = i;
    }

    for (auto &&i : v)
    {
        cout << i << endl;
    }

    v.at(9) = 111;
    cout << "v.at(9):" << v.at(9) << endl;

    try
    {
         //通过at方法访问vector， 越界抛出异常，程序继续运行
        v.at(10) = 112;
        cout << "v.at(10):" << v.at(10) << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        //通过索引访问越界， 程序直接崩溃
        v[10] = 113;
        cout << v[10] << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
