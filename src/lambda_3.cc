#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

//shared_ptr + std::function + lambda

struct TcpConn
{
    string addr;
    unsigned short port;
    
    std::function<void(int &)> leftcb_;

    void onLeft(const std::function<void(int &)> &cb)
    {
        leftcb_ = cb;
        cout << "onLeft" << endl;
    }
};

int main(int argc, const char **argv)
{
    TcpConn tcp;
    int x = 10;

    tcp.onLeft([](int &x) {
        cout << __func__ << ":" << __LINE__ << " x:" << x++ << endl;
    });

    return 0;
}