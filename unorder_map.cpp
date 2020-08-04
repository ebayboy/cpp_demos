#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

/* 
map : 底层实现rbtree 
unordered_map : 底层实现 unordered_map
*/
int main(int args, char **argv)
{
    unordered_map<int, string> u;

    u.insert(pair<int, string>(5, "unordered_map"));

    for (auto &&i : u)
    {
        cout << "key:" << i.first << "  value:" << i.second << endl;
    }

    map<int, string> m;
    m.insert(pair<int, string>(5, "map"));
     for (auto &&i : m)
    {
        cout << "key:" << i.first << "  value:" << i.second << endl;
    }


    return 0;
}
