#if 0
#include <iostream>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>

#endif

using namespace std;

struct Stu
{
    string name;

    Stu() : name(0){};
    Stu(string name) : name(name){};
};

void test(Stu *&s)
{
{
    if (s == nullptr)
    {
        s = new Stu(__func__);
    }
}

void test1(Stu *s)
{
    if (s == nullptr)
    {
        s = new Stu(__func__);
    }
}

int main(int args, char **argv)
{
    Stu *s = nullptr;
    Stu *s1 = nullptr;

    test(s);
    test1(s1);
    if (s)
    {
        cout << "s name:" << s->name << endl;
    }
    else
    {
        cout << "s1 == null!" << endl;
    }

    if (s1)
    {
        cout << "s1 name:" << s1->name << endl;
    }
    else
    {
        cout << "s1 == null!" << endl;
    }

    return 0;
}
