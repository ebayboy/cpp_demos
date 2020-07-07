// stdarg.h 可变参数

#include <iostream>
#include <stdarg.h>

using namespace std;

double SumofFloat(int count, ...)
{
    va_list ap;
    double sum = 0;

    va_start(ap, count);

    for(int i = 0; i < count; i++)
    {
        //va_arg 每次获取一个参数
        sum += va_arg(ap, double);
    }

    va_end(ap);
    
    return sum;
}

int main(int argc, const char **argv)
{
    auto ret = SumofFloat(3, 1.1f, 2.2, 3.3);

    cout << ret << endl;

    return 0;
}