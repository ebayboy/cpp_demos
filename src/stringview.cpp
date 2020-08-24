#include <string>
#include <iostream>
 
using namespace std;
 
// void process(const char* sv)
// void process(const string& sv)
void process(string_view sv)
{
    cout << sv << endl;
    for (char ch : sv)
        cout << ch;
    cout << sv[2] << endl;
}
 
int main()
{
    string_view sv = "hello"sv;
    cout << sv << endl;
    string_view sv2 = "hello";
    cout << sv2 << endl;
    string_view sv3 = "hello"s;
    cout << sv3 << endl;
    string_view sv4("hello", 4);
    cout << sv4 << endl;
    process("hello");
    process("hello"s);
}
