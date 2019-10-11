
/*
 * *在字符串数组中查找固定字符串
 * 10w次消耗时间 use time:427328(us)),
 * 比C++的vector查找快3倍
 * */
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>

char *strings[33] = { 
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

int find_str_in_strs(char **strings, char *value)
{
	char *string;     //字符串循环变量
	char *parValue;   //和value一样，只是易于回归
	while ((string = *strings++)!= NULL)
	{
		parValue = value;

		while (*string != '\0' && *parValue != '\0')  //两个字符串均未结束
		{
			if (*string != *parValue) 
			{
				break;
			} 
			else if ((*string++ == *parValue++) 
					&& (*string == '\0' && *parValue == '\0'))   
			{
				//两个字符串一致并且字符串中有一方结束
				return 1;
			}
		}
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
	char *text = "She said some groups have shown willingness to conduct dialogue with the government and reiterated the priority is to end violence and restore order in Hong Kong as soon as possible";

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

