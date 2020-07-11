/*
    可变参数模板实现
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
LINE:24 s:hello %s, age:%d, haha  //第一次调用模板Print, Value参数是workd
 value:world   
hello world 
LINE:24 s:, age:%d, haha  //输出world后，进入第二次递归Print(s:, age:%d, haha, age:30, )
 value:30
, age:30  //输出age:30后，进入第三次递归Print(s:, haha) ， 此时没有参数了， 调用Print(const char *)函数
LINE:12 s:, haha

, haha
*/

//参数递归打印完毕后调用Print(const char *s)
void Printf(const char *s)
{
    cout << "\nLINE:" << __LINE__ << " s:" << s << endl;
    while(*s) {
        if (*s == '%' && *++s != '%') {
            throw runtime_error("invalid format string: missing arguments!");
        }
        cout << *s++;
    }
}

//对每个参数递归调用模板Print， Value是递归的参数值
template<typename T, typename ... Args>
void Printf(const char *s, T value, Args ... args)
{
    cout << "\nLINE:" << __LINE__ << " s:" << s << " value:" << value << endl;
    while(*s) {
        if (*s == '%' && *++s != '%') {
            // is %d | %s | %f ...  , but not %%
            // value : args value
            cout << value;  //输出 world后， 进入递归Printf(,)
            return Printf(++s, args...);
        }
        cout << *s++;
    }
}

int main(int args, char **argv)
{
    Printf("hello %s, age:%d, haha\n", string("world"), 30);

    return 0;
}
