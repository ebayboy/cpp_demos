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
};

typedef std::shared_ptr<TcpConn> TcpConnPtr;

//完成lambda写法
void test_complete()
{
    std::function<TcpConnPtr()> conncb_;
    //[参数类型 = & ] (参数) ->返回值类型 {函数体}
    conncb_ = [] () -> TcpConnPtr {
        cout << "test_complete new tcp." << endl;
        return TcpConnPtr(new TcpConn);
    };
    //output : new tcp.
    conncb_();
}

//简略lambda写法
void test_simple()
{
    std::function<TcpConnPtr()> conncb_;
    // [] ( )
    conncb_ = [] {
        cout << "test_simple new tcp." << endl;
        return TcpConnPtr(new TcpConn);
    };
    //output : new tcp.
    conncb_();
}

void lambdainfunc_call(const TcpConnPtr &con)
{
    cout << "lambdainfunc_call" << endl; 
}

void lambdainfunc()
{
    std::function<TcpConnPtr()> conncb_;
    // [] ( )
    conncb_ = [] {
        cout << "test_simple new tcp." << endl;
        return TcpConnPtr(new TcpConn);
    };
    //output : new tcp.
    conncb_();

    lambdainfunc_call(conncb_());
}

int main(int argc, const char **argv)
{
    test_complete();

    test_simple();

    lambdainfunc();

    return 0;
}