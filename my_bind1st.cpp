// 实现bind1st函数对象

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

template <class Operation, class Param>
class my_binder1st
{
private:
    //function
    Operation m_op;
    //first param
    Param m_first;

public:
    //constructor
    my_binder1st(Operation op, Param first)
    {
        m_op = op;
        m_first = first;
    }

    //operator reload, Param: type
    Param operator()(Param second)
    {
        return m_op(m_first, second);
    }
};


template <class Operation, class Param> //param template
my_binder1st<Operation, Param> //return type
my_bind1st(Operation op, Param first)
{
    //调用构造函数初始化对象： my_binder1st<Operation, Param>(op, first);
    return my_binder1st<Operation, Param>(op, first);
}

int main(int args, char **argv)
{
    my_binder1st<plus<int>, int> plusobj=my_bind1st(plus<int>(), 10);

    cout << plusobj(20) << endl;

    return 0;
}