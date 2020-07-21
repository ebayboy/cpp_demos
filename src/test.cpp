/*

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int u = 0;

int test()
{
    u++;
    cout << "in u:" << u << endl;
    return 5;
}

int main(int args, char **argv)
{
    int a[5] = {1, 2, 3, 4, 5};

    u = 1;

    cout << "before:" << u << endl;

    a[u] = test();

    for (auto &&i : a)
    {
        cout << i << endl;
    }

    cout << "end:" << u << endl;
    cout << u << endl;

    return 0;
}
