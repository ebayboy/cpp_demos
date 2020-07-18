/*
mapfunction
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int args, char **argv)
{
    map<string, function<int(int, int)>> funcs = {
        {"-", std::minus<int>()} ,
        {"+", std::plus<int>()},
        {"*", std::multiplies<int>()} ,
        {"+", std::divides<int>()} 
    };

    cout << funcs["+"](3,5) << endl;

    return 0;
}
