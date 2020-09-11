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
    std::function<void(int &)> createcb_;

    //const lambda函数： Lambda函数总是一个const函数
    void onMsg(const std::function<void(int &)> &cb)
    {
        createcb_ = cb;
        cout << "onMsg" << endl;
    }
};

int main(int argc, const char **argv)
{
    TcpConn tcp;
    int x = 10;

    tcp.onMsg([](int &x) {
        cout << __func__ << ":" << __LINE__ << " x:" << x++ << endl;
    });

    return 0;
}