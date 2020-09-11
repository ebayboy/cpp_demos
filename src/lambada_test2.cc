#include <iostream>
using namespace std;
struct Foo
{
    int x = 1;

    void foo(int x)
    {
        auto f = [x,this] {
            cout << x << endl;
            cout << "this->x:" << this->x << endl;
        };
        f();
    }
};

int main(int argc, const char **argv)
{
    Foo f;
    f.foo(2);
    return 0;
}
