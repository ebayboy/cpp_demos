#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<string> split(string strTime, string seps)
{
    vector<string> result;
    string temp("");
    strTime += ')'; //字符串结束标记，方便将最后一个单词入vector
    for (size_t i = 0; i < strTime.size(); i++)
    {
        if (strTime[i] == '(' || strTime[i] == ')' || strTime[i] == ',' || strTime[i] == '/')
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += strTime[i];
        }
    }
    
    return result;
}

int main()
{
    string strtime = "GT(ip_total_5m/all_total_5m,0.1)";
    vector<string> result = split(strtime);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << "  ";
    }
    return 0;
}