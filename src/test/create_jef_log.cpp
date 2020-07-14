/*
    1590996727.676|+ #grp00|+ #t.com|+ #1.1.1.1|+ #/b.css|+ #404|+ #6.00
    13/Jul/2020:15:10:19 +0800 nginx_log#?#  :a04-r08-i133-8-738lxl8.jd.local#?#  :25053#?#  :1594624219.337#?#  :10.226.149.215#?#  :53410#?#  :/#?#  :400#?#  :191#?#  :86#?#  :-#?#  :-#?#  :LF-1-PUB-NX#?#  :0#?#  :10.226.133.8#?#  :10.226.133.8#?#  :80#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :0.000#?#  :1#?#  :0#?#  :1#?#  :0#?#  :_#?#  :Mozilla/5.0#?#  :-#?#  :-#?#  :c56b00175e09d393a8225f76572b8a40#?#  :GET#?#  :-#?#  :http#?#  :/#?#  :123#?#  :10.226.133.8@123#?#  :HTTP/1.1#?#  :-#?#  :-#?#  :-#?#  :22#?#  :-#?#  :-#?#  :/#?#  :-#?#  :-#?#  :-#?#  :123#?#  :-#?#  :#?#  :-#?#  :#?#  :
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <cstdio>
#include <sys/time.h>

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

void updateUsedCols(vector<int> usedColsIdx, vector<string> vals, vector<string> &strs)
{
    for (size_t i = 0; i < usedColsIdx.size(); i++)
    {
        int idx = usedColsIdx[i];
        strs[idx] = vals[i];
    }
}

string getLocalTime()
{
    //29/May/2020:16:38:19 +0800 nginx_log
    vector<string> mon = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"};
    time_t t;
    tm *lt;
    t = time(NULL);
    lt = localtime(&t);

    stringstream ss;
    string stm;
    int tm_year = lt->tm_year + 1900;
    //int tm_month = lt->tm_mon + 1;

    ss << lt->tm_mday << "/" << mon[lt->tm_mon] << "/" << tm_year << ":" << lt->tm_hour << ":" << lt->tm_min << ":" << lt->tm_sec << " +0800 nginx_log";

    return ss.str();
}

/* 1265222655.591(ms) */
string getCurrentTimeMsec()
{
    struct timeval tv;
    stringstream ss;

    gettimeofday(&tv, NULL);
    long sec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    long usec = tv.tv_usec % 1000;

    ss << sec << "." << usec;

    return ss.str();
}

int main(int args, char **argv)
{
    vector<string> cols = {
        "time_local_nginx_log",
        "hostname",
        "pid",
        "msec",
        "remote_addr",
        "remote_port",
        "document_uri",
        "status",
        "bytes_sent",
        "request_length",
        "ssl_protocol",
        "ssl_session_reused",
        "C_IDC",
        "tcpinfo_rtt",
        "host",
        "server_addr",
        "server_port",
        "upstream_http_name",
        "upstream_addr",
        "upstream_http_port",
        "upstream_connect_time",
        "upstream_header_time",
        "upstream_response_time",
        "request_time",
        "connections_active",
        "connections_reading",
        "connection_requests",
        "connections_writing",
        "server_name",
        "http_user_agent",
        "anti_reason",
        "anti_action",
        "request_id",
        "request_method",
        "http_referer",
        "scheme",
        "uri",
        "instance_id",
        "host@$instance_id",
        "server_protocol",
        "sent_http_content_range",
        "content_type",
        "content_length",
        "body_bytes_sent",
        "upstream_bytes_received",
        "upstream_status",
        "request_uri",
        "anti_remote_addr",
        "anti_status",
        "anti_payload",
        "user_pin",
        "upstream_cache_status",
        "anti_typ",
        "upstream_err",
        "anti_req_raw",
        "anti_resp_raw"};

    vector<string> usedCols = {
        "time_local_nginx_log", //0 //13/Jul/2020:19:13:19 +0800 nginx_log
        "instance_id",          //1 //123
        "host",                 //2 //10.226.133.8
        "remote_addr",          //3 //10.226.149.215
        "msec",                 //4 //1590741499.339
        "status",               //5 //200 | 400
        "uri",                  //6 //  /
        "http_user_agent",      //7 // Mozilla/5.0
        "anti_typ"              //8 // ""
    };

    vector<int> usedColsIdx;
    for (size_t i = 0; i < usedCols.size(); i++)
    {
        bool found = false;
        for (size_t j = 0; i < cols.size(); j++)
        {
            if (usedCols[i].compare(cols[j]) == 0)
            {
                usedColsIdx.push_back(j);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Error: not find index!" << endl;
            return -1;
        }
    }

    string s = "29/May/2020:16:38:19 +0800 nginx_log#?#  :a04-r08-i133-8-738lxl8.jd.local#?#  :3150#?#  :1590741499.339#?#  :10.226.149.215#?#  :53576#?#  :/#?#  :400#?#  :191#?#  :86#?#  :-#?#  :-#?#  :LF-1-PUB-NX#?#  :0#?#  :10.226.133.8#?#  :10.226.133.8#?#  :80#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :-#?#  :0.000#?#  :1#?#  :0#?#  :1#?#  :0#?#  :_#?#  :Mozilla/5.0#?#  :-#?#  :-#?#  :0655e57925dc5b30e80979494658f7a8#?#  :GET#?#  :-#?#  :http#?#  :/#?#  :123#?#  :10.226.133.8@123#?#  :HTTP/1.1#?#  :-#?#  :-#?#  :-#?#  :22#?#  :-#?#  :-#?#  :/#?#  :-#?#  :-#?#  :-#?#  :123#?#  :-#?#  :#?#  :-#?#  :#?#  :";
    string sep = "#?#  :";
    vector<string> strs;
    stringSplit(s, sep, strs);

    vector<string> hosts;
    vector<string> remote_addrs;

    for (size_t i = 1; i < 100; i++)
    {
        // 100 hosts
        stringstream ss;
        ss << "10.226.133." << i;
        hosts.push_back(ss.str());
    }

    size_t count = 1000;
    for (size_t i = 1; i < 254 && count > 0; i++, count--)
    {
        // 1000 remote_addr
        //10.226.1.1
        stringstream ss;
        ss << "10.226." << i;
        for (size_t j = 1; j < 254; j++)
        {
            stringstream ss1;
            ss1 << ss.str() << "." << j;
            remote_addrs.push_back(ss1.str());
        }
    }

    //每秒插入10条数据

    vector<string> usedColsVals = {"111", "123", "10.226.133.8", "10.226.149.215", "555", "666", "777", "888", "999"};
    string remote_addr = "10.226.149.215"; //param1
    string host = "10.226.133.8";          //param2
    string instance_id = "123";
    string status = "200";
    string uri = "/";
    string user_agent = "Mozilla/5.0";
    string anti_typ = "";
    string localtime = getLocalTime();
    string msec = getCurrentTimeMsec();

    usedColsVals[0] = localtime;
    usedColsVals[1] = instance_id;
    usedColsVals[2] = host;
    usedColsVals[3] = remote_addr;
    usedColsVals[4] = msec;
    usedColsVals[5] = status;
    usedColsVals[6] = uri;
    usedColsVals[7] = user_agent;
    usedColsVals[8] = anti_typ;

    updateUsedCols(usedColsIdx, usedColsVals, strs);

    cout << "after udpate:" << endl;
    for (auto &&i : usedColsIdx)
    {
        cout << cols[i] << ":" << strs[i] << endl;
    }

    return 0;
}
