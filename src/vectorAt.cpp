/*
    vector通过at访问和通过索引访问的问题（推荐通过at访问，异常程序不至于崩溃）
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testV()
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
}

void testV2()
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

    //通过at方法访问vector， 越界抛出异常，程序继续运行
    v.at(10) = 112;
    cout << "v.at(10):" << v.at(10) << endl;
}

//noexcept： 如果函数内部有异常， 则程序终止, 异常必须消化在程序内部
void testV3() noexcept
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

    //通过at方法访问vector， 越界抛出异常，程序继续运行
    v.at(10) = 112;
    cout << "v.at(10):" << v.at(10) << endl;
}

int main(int args, char **argv)
{
   // testV();

    try
    {
        testV2();
    }
    catch (exception &e)
    {
        cout << "catch V2:" << e.what() << endl;
    }

    cout << "end" << endl;

    
    testV3();
    cout << "testV3 ok!" << endl;

    return 0;
}
