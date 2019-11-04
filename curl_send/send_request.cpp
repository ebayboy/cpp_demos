
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <exception>
#include <cstring>
#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;

#ifdef DEBUG

#define DP(format,...) printf(__FILE__ ":%d " #format "\n", __LINE__, ##__VA_ARGS__)

#else

#define DP(fmt, ...)

#endif

void ParseResFile(string fname, string ofile)
{
    ifstream ifs; //标准输入流
    ifs.open(fname.c_str());
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    JSONCPP_STRING errs;
    Json::Value root;

    //从ifs中读取数据到jsonRoot
    if (!parseFromStream(builder, ifs, &root, &errs))
    {
        return;
    }

    FILE *fp = fopen(ofile.c_str(), "a+");
	if (fp == NULL)
	{
		DP("Error: fopen!");
		return;
	}

    //读取根节点信息
    int code = root["code"].asInt();
    string message = root["message"].asString();
    int total = root["total"].asInt();
    int size = root["size"].asInt();

	if (code == -1) 
	{
		DP("code = -1!");
		exit(-1);
	}
	if (size == 0) 
	{
		DP("read size==0, exit!");
		exit(0);
	}

    cout << "code:" << code << endl;
    cout << "message:" << message << endl;
    cout << "total:" << total << endl;
    cout << "size:" << size << endl;

    //读取数组信息
    cout << "Data:" << endl;
    Json::Value dataItem;
    for (unsigned int i = 0; i < root["data"].size(); i++)
    {
        dataItem = root["data"][i];
        //cout << "waf_hit_id:" << dataItem["waf_hit_id"].asString() << endl;
		string req = dataItem["request_uri"].asString();
		req += "\n";
        //cout << "request_uri:" << req << endl;
		fwrite(req.c_str(), req.size(), 1, fp);
	}
    cout << endl;
    cout << "Reading Complete!" << endl;

	if (fp)
	{
		fclose(fp);
	}
}

static size_t ncWriteFile(void* buffer, size_t size, size_t nmemb, void* lpVoid)
{
    FILE *fp = (FILE *)lpVoid;
    size_t nWrite = 0;

    if (fp == NULL || buffer == NULL)
    {
        return -1;
    }

    nWrite = fwrite(buffer, size, nmemb, fp);

    return nWrite;
}

__attribute__((unused))
void SendGet(string url, string fname_out)
{
    FILE *fp;
    CURL *curl;
    CURLcode res;

    fp = fopen(fname_out.c_str(), "a+");
    if (fp == NULL)
    {
        DP("Error: open file error!");
        return ;
    }

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type:application/json");

    curl = curl_easy_init();
    if (curl)
    {
        res = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());         //请求地址
        res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);      //请求头
        res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ncWriteFile);   //写入数据的回调
        res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)fp);        //文件指针
        res = curl_easy_perform(curl);

    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    if (fp)
    {
        fclose(fp);
    }
}

int SendPost(string url, string post_data, FILE * fp)
{
    CURL *curl = NULL;
    CURLcode res;
    struct curl_slist *headers = NULL;
    int ret = 0;

    if (url.size() == 0 ||  post_data.size() == 0 || fp == NULL)
    {
        DP("Error param error!;");
        return ret;
    }

    curl = curl_easy_init();
    if (!curl)
    {
        DP("Error: curl_easy_init");
        ret = -1;
        goto out;
    }

    res = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_setopt(curl, CURLOPT_POST, 1);

    headers = curl_slist_append(headers, "Content-Type:application/json");
    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ncWriteFile);
    res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)fp);

    //set POST Data
    res = curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
    res = curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) post_data.size());

    res = curl_easy_perform(curl);
    if (res != 0)
    {
        DP("Error: curl_easy_perform() failed:%s", curl_easy_strerror(res));
        ret = -1;
        goto out;
    }

out:
    if (headers)
    {
        curl_slist_free_all(headers);
    }
    if (curl)
    {
        curl_easy_cleanup(curl);
    }

    return ret;
}

int main(int argc, char **argv)
{
    string url="http://logeye.jdcloud.com/api/v2/search";
    FILE *fp = NULL;

    if (argc < 3)
    {
        DP("Usage: $0 date fetch_loops! argc:[%d]", argc);
        return -1;
    }

    string date = argv[1];
    int loops = atoi(argv[2]);

    string uuid = "\"uuid\": \"87556c6688ce49a9bcd5950b226fdc01\",";
    string appName = "\"appName\": [\"jsec-sgw-logserver\"],";

    string timeRange = "\"timeRange\": {\"start\" : \"" + date + " 00:00:00\"" + ", \"end\" : \"" + date + " 23:59:59\"},";
    string resp = "\"resp\":[\"request_uri\", \"waf_hit_id\"],";
    string size = "\"size\": 100";

    string match = "\"match\": [ { \"regexp\" : { \"waf_hit_id\" : [\"10000|10007|10015|10016|10017|10019|10028|10029|10030|10031|10044|10045|10056|10057|10073|10091|10092|10093|10095|10096|10110|10111|10112|10113|10125|10126|10127|10129|10134|10135|10146|10196|10215|10230|10260\"]}, \"regexp\" : {\"request_uri\" : [\".*\\\\?.*\"]} }], ";

    for (int i = 0; i < loops; i++)
    {
        string ofile = date + "." + std::to_string(i);
        fp = fopen(ofile.c_str(), "w+");
        if (fp == NULL)
        {
            DP("Error: open file!");
            return -1;
        }

        string from = "\"from\":" + std::to_string(i*100) + ",";
        string post_data = "{" + uuid + appName + timeRange + match + resp + from + size + "}";

        //DP("post_data:%s", post_data.c_str());

        if (SendPost(url, post_data, fp) != 0)
        {
            DP("Error: SendPost!");
        }
        DP("Send: %d ok!", i);

        if (fp)
        {
            fclose(fp);
        }

        ParseResFile(ofile, date + ".txt");
    }

    return 0;
}
