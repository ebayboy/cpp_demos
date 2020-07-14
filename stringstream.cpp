
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    ofstream of("./1.txt");
    if (of.bad())
    {
        cerr << "error!" << endl;
        return -1;
    }

    stringstream ss;

    //清空stringstream使用 ss("");

    for (size_t i = 0; i < 5; i++)
    {
        ss << "age: " << i << endl;
    }

    of << ss.str();

    cout << "before clear data:" << ss.str() << endl;
    ss.str("");
    cout << "after clear data:" << ss.str() << endl;

    of.close();

    return 0;
}
