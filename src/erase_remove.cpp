/*
    erase && remove
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int args, char **argv)
{
    vector<int> v;

    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
        if (i == 5 || i == 8)
            v.push_back(i);
    }

    for (auto &&i : v)
    {
        cout << "i:" << i << endl;
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == 5)
        {
            //test erase
            v.erase(it--); //元素删除后迭代器需要退1，保证不丢掉重复的元素5
        }
    }
    //erase删除后， v的元素减少
    cout << "after erase size:" << v.size() << endl;

    cout << "after remove show:================" << endl;
    for (auto &&i : v)
    {
        cout << "i:" << i << endl;
    }

    auto it = std::remove(v.begin(),v.end(), 8);
    if (it != v.end()) {
        cout << "remove:" << *it << endl;
    }

    //remove后size没减少， 而是将删除的元素放到end后面
    cout << "after remove: size:" <<  v.size() << endl;
    cout << "end:" << *v.end() << endl;
    for (auto &&i : v)
    {
        cout << "i:"  << i << endl;
    }
    

    return 0;
}
