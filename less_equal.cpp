#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(int args, char **argv)
{
    //template<class _Ty = void> struct std::less_equal<_Ty>
    std::less_equal<int> le;
    cout  << le(5, 10) << endl;

    return 0;
}