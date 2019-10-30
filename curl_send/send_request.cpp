
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <exception>
#include <cstring>
#include <iostream>

using namespace std;

#ifdef DEBUG

#define DP(format,...) printf(__FILE__ ":%d " #format "\n", __LINE__, ##__VA_ARGS__)

#else

#define DP(fmt, ...)  

#endif

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
	if (!curl) {
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
    string post_data = "{"	\
                       "\"uuid\": \"87556c6688ce49a9bcd5950b226fdc01\"," \
                       "\"appName\": [\"jsec-sgw-logserver\"]," \
                       "\"timeRange\": {},"	\
                       "\"match\": [],"	\
                       "\"resp\": [],"	\
                       "\"from\": 0,"	\
                       "\"size\": 5 }";

	FILE *fp = NULL;

	fp = fopen("output.json", "w+");
	if (fp == NULL) 
	{
		DP("Error: open file!");
		return -1;
	}

	for (int i = 0; i < 1; i++)
	{
		if (SendPost(url, post_data, fp) != 0) 
		{
			DP("Error: SendPost!");
		}
		DP("Send: %d ok!", i);
	}

	if (fp)
	{
		fclose(fp);
	}

    return 0;
}
