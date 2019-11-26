/* string */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "hello";
    string str2 = "world";
    string str3;
    int len;

    str3 = str1;
    cout << "str3:" << str3 << endl;

    str3 = str1 + str3;
    cout << "str3:" << str3 << endl;

    len = str3.size();
    cout << "len:" << len << endl;

    string str4("str4");
    cout << "str4: " << str4 << endl;
    cout << "str4: size: " << str4.size() << endl;
    cout << "str4: length: " << str4.length() << endl;
    cout << "str4[2]:" << str4[2] << endl;

    cout << "ret: " << str4.compare("str4") << endl;
    cout << "ret: " << str4.compare("str45") << endl;

    // 比较str4的前三位和后一个字符串
    cout << "ret: " << str4.compare(0, 3, "str") << endl;

    // 比较str4和后一个字符串的前缀
    cout << "ret: " << str4.compare(0, str4.size(), "str45", 0, str4.size()) << endl;

    return 0;
}
