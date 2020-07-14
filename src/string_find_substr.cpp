
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void stringSplit(string const s, string sep, vector<string> &strs)
{
    string::size_type pos = 0, n;

    while (pos != string::npos)
    {
        n = s.find(sep, pos);
        if (n == string::npos)
        {
            break;
        }
        strs.push_back(s.substr(pos, n - pos));
        pos = n + sep.size();
    }
}

int main()
{
    string const s = "29/May/2020:16:38:19 +0800 nginx_log#?#  :a04-r08-i133-8-738lxl8.jd.local#?#  :3150#?#  :1590741499.339#?#  :10.226.149.215#?#  :53576#?#  :/#?#  :400#?#  :191#?#  :86#?#  :-#?#  :-#?#  :LF-1-PUB-NX#?#  :0#?#  :10.226.133.8#?#  :10.226.133.8#?#  :80#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :0.000#?#  :1#?#  :0#?#  :1#?#  :0#?#  :_#?#  :Mozilla/5.0#?#  :-#?#  :-#?#  :0655e57925dc5b30e80979494658f7a8#?#  :GET#?#  :-#?#  :http#?#  :/#?#  :123#?#  :10.226.133.8@123#?#  :HTTP/1.1#?#  :-#?#  :-#?#  :-#?#  :22#?#  :-#?#  :-#?#  :/#?#  :-#?#  :-#?#  :-#?#  :123#?#  :-#?#  :#?#  :-#?#  :#?#  :";
    string sep = "#?#  :";
    vector<string> strs;

    stringSplit(s, sep, strs);

    for (auto &&i : strs)
    {
        cout << i << endl; 
    }
    

    return 0;
}