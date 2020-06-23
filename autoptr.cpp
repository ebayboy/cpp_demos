#include <iostream>
#include <string>
#include <memory> //used in linux

using namespace std;

int main(int argc, char const *argv[])
{
    auto_ptr<string> p1 (new string ("hello world"));

    cout << "p1:" << *p1 << endl;

    return 0;
}

