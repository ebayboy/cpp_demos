/*
    我们需要定义一个表示平面的点（Point）类，
    这个类有两个成员变量，分别表示横坐标和纵坐标，
    并且这两个坐标的类型可以是int、float、double等类型。
    因此可能写出类似Point_int_int、Point_float_int、Point_float_float等这样的类。通过类模板，我们只需要写一个类。

    default constructor;
    constructor with param;
    overload: = + <<
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T1, class T2>
class Point_T
{
private:
    T1 a;
    T2 b;

public:
    //default constructor
    Point_T() : a(0), b(0){};

    //constructor with params
    Point_T(T1 ta, T2 tb) : a(ta), b(tb){};

#if 0
    //参数和返回值使用引用类型
    //overload =
    Point_T<T1, T2> &operator=(Point_T<T1, T2> &pt)
    {
        this->a = pt.a;
        this->b = pt.b;

        //return refrence type
        return *this;
    }
#else
    //参数和返回值使用值传递
    Point_T<T1, T2> operator=(Point_T<T1, T2> pt)
    {
        this->a = pt.a;
        this->b = pt.b;

        //return refrence type
        return *this;
    }
#endif

    //overload +
    Point_T<T1, T2> operator+(const Point_T<T1, T2> &pt1)
    {
        Point_T<T1, T2> temp;
        temp.a = this->a + pt1.a;
        temp.b = this->b + pt1.b;
        return temp;
    }

    //loverload <<
    friend ostream& operator << (ostream& out, const Point_T<T1,T2>& pt)    
    {
        out << "a:" << pt.a << " b:" << pt.b << endl;
        return out;
    }
};

int main(int args, char **argv)
{
    Point_T<int, int> intP1(1, 2);
    Point_T<int, int> intP2;
    Point_T<int, int> intP3(3, 4);

    cout << "initP1:" << intP1 << endl;

    intP2 = intP1; // overload =
    cout << "initP2:" << intP1 << endl;

#if 0
    //参数和返回值使用引用传递
    Point_T<int, int> intT = intP1 + intP3;
#else
    //参数和返回值使用值传递
    Point_T<int, int> intT;
    intT = intP1 + intP3;
#endif
    cout << "intT:" << intT << endl;

    cout << "intP3:" << intP3 << endl;

    return 0;
}
