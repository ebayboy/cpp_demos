#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

struct TcpConn
{
    string addr;
    unsigned short port;
};

typedef std::shared_ptr<TcpConn> TcpConnPtr;

int main(int argc, const char **argv)
{
    std::function<TcpConnPtr()> conncb_;
    conncb_ = [] {
        cout << "new tcp." << endl;
        return TcpConnPtr(new TcpConn);
    };
    //output : new tcp.
    conncb_();

    return 0;
}