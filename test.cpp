
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 5};

    int a = std::accumulate(v.begin(), v.end(), 0);

    cout << a << endl;

    vector<bool> v1 = {true, true, true};
    bool b = std::accumulate(v1.begin(), v1.end(), true,
                             [](bool x, bool y) {
                                 cout << "x:" << x << endl;
                                 cout << "y:" << y << endl;
                                 bool z = x & y;
                                 cout << "z:" << z << endl;
                                 return z;
                             });
    cout << b << endl;

    return 0;
}
