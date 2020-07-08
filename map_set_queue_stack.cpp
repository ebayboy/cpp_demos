#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void testSet()
{
    std::set<int> s;

    for (size_t i = 1; i < 5; i++)
    {
        s.insert(i);
    }

    s.insert(3);

    for (auto i : s)
    {
        cout << i << endl;
        if (i == 3) {
            s.erase(i);
        }
    }

    cout <<"after erase:" << endl;
    
    for (auto &&i : s)
    {
        cout << i << endl; 
    }
    

}

void testQueue()
{
    std::queue<int> q;

    for (size_t i = 1; i < 10; i++)
    {
        q.push(i);
    }

    cout << "size:" << q.size() << endl;

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void testStack()
{
    std::stack<int> q;

    for (size_t i = 0; i < 5; i++)
    {
        q.push(i) ;
    }

    while (!q.empty())
    {
        cout << "top:" << q.top()  << endl;
        q.pop();
    }
}

void testMap()
{
    map<string, int> m;

    //insert
    for (size_t i = 0; i < 5; i++)
    {
        m.insert(pair<string, int>(string("fanpf"), 30));
        m.insert(pair<string, int>(string("rose"), 31));
    }

    //erase key rose
    m.erase("rose");

    //loop show 
    for (auto &&i : m)
    {
       cout << "first:" << i.first << "  second:" <<i.second << endl;
    }

}

int main(int args, char **argv)
{
    //testSet();
//    testQueue();
//    testStack();

    testMap();

    return 0;
}