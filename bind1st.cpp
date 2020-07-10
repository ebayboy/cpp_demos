/*
    bind1st && bind2st
*/
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(int args, char **argv)
{
    binder1st<plus<int> > plusObj = bind1st(plus<int>(), 10);

    cout << plusObj(20) << endl;

    vector<int> v;

    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    int n = count_if(v.begin(), v.end(), bind1st(less_equal<int>(), 4));
    cout << "n:" << n << endl;

    return 0;
}