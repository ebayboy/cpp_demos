
/*
 * *在字符串数组中查找固定字符串
 * 10w次消耗时间 use time:1714592(us))
 * */
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector <string> strings = { 
	"all",
	"select",
	"as",
	"top"
	"concat",
	"join",
	"left",
	"right",
	"from",
	"where",
	"on",
	"like",
	"between",
	"insert",
	"into",
	"values",
	"delete",
	"update",
	"drop",
	"sleep",
	"and",
	"or",
	"DISTINCT",
	"ALTER",
	"CREATE",
	"TRIGGER",
	"SET",
	"DECLARE",
	"FETCH",
	"PREPARE",
	"EXECUTE",
	"DESCRIBE",
	"end"
};

int find_str_in_strs(vector<string> &strings, string value)
{
	vector<string>::iterator it = std::find(strings.begin(), strings.end(), value);
	
	if (it != strings.end()) {
		return 1;
	}

	return 0;
}

long long get_time_now() 
{
	struct timeval tv; 
	gettimeofday(&tv,NULL);
	return tv.tv_sec*1000*1000 + tv.tv_usec;
}

int main()
{
	/* add strings to vec */
	char *text = (char *)"She said some groups have shown willingness to conduct dialogue with the government and reiterated the priority is to end violence and restore order in Hong Kong as soon as possible";

	char payload[512] = {0};

	char *p = payload;

	long long st = get_time_now();

	for (int i = 0; i < 100000; i++) {
		strcpy(payload, text);
		p = strtok(payload, " ");
		while(p) {
			find_str_in_strs(strings, p);
			p = strtok(NULL, " ");
		}
	}

	printf("use time:%llu(us)\n", get_time_now() - st);

	return 0;
}

