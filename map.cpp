#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void testMap()
{
    map<string, int> m;

    //insert
    for (size_t i = 0; i < 5; i++)
    {
        m.insert(pair<string, int>(string("fanpf"), 30));
        m.insert(pair<string, int>(string("rose"), 31));
        m.insert(pair<string, int>(string("kevin"), 32));
    }

    //find key, then erase node
    std::map<std::string, int>::iterator r = m.find("kevin");
    if (r != m.end()) {
        cout << "find: " << (*r).first <<  " second:" << (*r).second << endl;
        m.erase(r);
    }

    //erase by key
    m.erase("rose");

    //loop show 
    for (auto &&i : m)
    {
       cout << "first:" << i.first << "  second:" <<i.second << endl;
    }
}

int main(int args, char **argv)
{
    testMap();

    return 0;
}