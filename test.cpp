#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main(int args, char **argv)
{
    //std 模板函数对象
    std::minus<int> int_minus;
    cout << "int_minum(4,1): " << int_minus(4, 1) << endl;

    std::greater<int> int_greater;
    bool ret = int_greater(1, 4);
    cout << "ret:" << ret << endl;

    return 0;
}