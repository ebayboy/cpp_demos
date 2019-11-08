
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <exception>
#include <cstring>
#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;

typedef struct {
	string date_to;
	string date_from;
	string match;
	string uuid;
	string appName;
	string resp;
	int size;
} reqcfg_t;

#ifdef DEBUG

#define DP(format,...) printf(__FILE__ ":%d " #format "\n", __LINE__, ##__VA_ARGS__)

#else

#define DP(fmt, ...)

#endif

#define CFG_SET(cfg, x, v) (cfg)->x = v

int ParseCfgFile(string fname, reqcfg_t *cfg)
{
    ifstream ifs; //标准输入流
    ifs.open(fname.c_str());
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    JSONCPP_STRING errs;
    Json::Value root;
	FILE *fp = NULL;
	int ret = 0;

    if (!parseFromStream(builder, ifs, &root, &errs))
    {
        ret = -1;
		goto out;
    }

	CFG_SET(cfg, date_to, root["date_to"].asString().c_str());
	CFG_SET(cfg, date_from, root["date_from"].asString().c_str());
	CFG_SET(cfg, match, root["match"].asString().c_str());

out:
	if (fp)
	{
		fclose(fp);
	}

	ifs.close();

	return ret;
}


int ParseResFile(string fname, string ofile)
{
    ifstream ifs; //标准输入流
    ifs.open(fname.c_str());
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    JSONCPP_STRING errs;
    Json::Value root;
	int ret = 0;
	FILE *fp = NULL;
	int code, total, size , status;
	string message, error, req;
	unsigned int i = 0;
    Json::Value dataItem;

    //从ifs中读取数据到jsonRoot
    if (!parseFromStream(builder, ifs, &root, &errs))
    {
        ret = -1;
		goto out;
    }

    //读取根节点信息
	code = root["code"].asInt();
	message = root["message"].asString();
	total = root["total"].asInt();
	size = root["size"].asInt();
	status = root["status"].asInt();
	error = root["error"].asString();

	DP("code = %d!", code);
	DP("status = %d!", status);

	if (code != 0 || status == 400 || error.size() > 0) 
	{
		DP("code = %d status:%d error:%s", code, status, error.c_str());
		ret = -1;
		goto out;
	}

	if (size == 0) 
	{
		DP("read size==0, exit!");
		ret = -1;
		goto out;
	}

    cout << "code:" << code << endl;
    cout << "message:" << message << endl;
    cout << "total:" << total << endl;
    cout << "size:" << size << endl;

	fp = fopen(ofile.c_str(), "a+");
	if (fp == NULL)
	{
		DP("Error: fopen!");
		ret = -1;
		goto out;
	}
    //读取数组信息
    cout << "Data:" << endl;
    for (i = 0; i < root["data"].size(); i++)
    {
        dataItem = root["data"][i];
        //cout << "waf_hit_id:" << dataItem["waf_hit_id"].asString() << endl;
		req = dataItem["request_uri"].asString();
		req += "\n";
        //cout << "request_uri:" << req << endl;
		fwrite(req.c_str(), req.size(), 1, fp);
	}
    cout << endl;
    cout << "Reading Complete!" << endl;

out:
	if (fp)
	{
		fclose(fp);
	}

	if (ifs.is_open()){
		ifs.close();
	}

	return ret;
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
		ret = -1;
		goto out;
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
	int loops = 0;

	reqcfg_t cfg;
	memset(&cfg, 0, sizeof(reqcfg_t));

	CFG_SET(&cfg, uuid, "\"87556c6688ce49a9bcd5950b226fdc01\"");
	CFG_SET(&cfg, appName, "\"jsec-sgw-logserver\"");
	CFG_SET(&cfg, resp, "\"request_uri\"");
	cfg.size = 100;

	if (ParseCfgFile("cfg.json", &cfg) == -1) 
	{
		DP("Error: ParseCfgFile!");
		return -1;
	}

	while(1) 
	{
        DP("Sending: %d!", loops);

        string ofile = std::to_string(loops);
        fp = fopen(ofile.c_str(), "w+");
        if (fp == NULL)
        {
            DP("Error: open file!");
            return -1;
        }

        string from = "\"from\":" + std::to_string(loops*100);
		string timeRange = ",\"timeRange\": {\"start\" : \"" + cfg.date_from + "\"" + ", \"end\" : \"" + cfg.date_to + "\"}";

        string post_data = "{";
		if (cfg.uuid.size() > 0) {
			post_data += "\"uuid\":" + cfg.uuid;
		}
		if (cfg.appName.size() > 0) {
			post_data += ",\"appName\":[" + cfg.appName + "]";
		}
		if (timeRange.size() > 0) {
			post_data += timeRange;
		}
		if (cfg.match.size() > 0) {
			post_data += ",\"match\":" + cfg.match;
		}
		if (cfg.resp.size() > 0) {
			post_data += ",\"resp\":[" + cfg.resp + "]";
		}
		if (from.size() > 0) {
			post_data += "," + from;
		}
		post_data += ",\"size\":" + std::to_string(cfg.size);

		//end
		post_data +="}";

        DP("post_data:%s", post_data.c_str());

        if (SendPost(url, post_data, fp) == -1)
        {
            DP("Error: SendPost Error!");
			return -1;
        }

        if (fp)
        {
            fclose(fp);
        }

        if (ParseResFile(ofile, "output.txt") == -1) 
		{
			DP("Error: ParseResFile");
			return -1;
		}

		string cmd = "rm -rf " + ofile;
		system(cmd.c_str());

		loops++;
    }

    return 0;
}
