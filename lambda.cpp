#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//lambda
//[外部变量访问方式说明符] (参数表) -> 返回值类型 { 语句块 }
//其中，“外部变量访问方式说明符”可以是=或&，表示{}中用到的、定义在{}外面的变量在{}中是否允许被改变。
//=表示不允许，&表示允许。
//当然，在{}中也可以不使用定义在外面的变量。“-> 返回值类型”可以省略。

int main(int args, char **argv)
{
    int a[] = {4, 2, 1, 3};

    //值传递
    sort(a, a + 4, [=](int x, int y) -> bool { return x < y; });
    for_each(a, a + 4, [=](int x) -> void { cout << x << endl; });

    //引用传递，{}内可以改变外部变得值
    int b[] = {4, 2, 1, 3};
    int total = 0; 
    //& 改变外部变量total的值
    for_each(b, b + 4, [&](int &x) -> void { total +=x; x*=2; });
    for_each(b, b + 4, [=](int x) -> void { cout << x << endl; });
    cout << "total:" << total << endl;

    vector<string> v ={"111", "222", "333"};

    for_each(v.begin(),v.end(), [&](string x) -> void{ cout << x << endl;} );

    return 0;
}