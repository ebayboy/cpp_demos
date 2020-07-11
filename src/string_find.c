
/*
 * *在字符串数组中查找固定字符串
 * 10w次消耗时间 use time:427328(us)),
 * 比C++的vector查找快3倍
 * */
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#define STRS_MAX 128
#define STRS_LEN_MAX 64

char *str_to_lower(char* string, size_t  slen)
{
    int i;

    if (string == NULL || slen == 0) {
        return NULL;
    }   

    for (i = 0; i < slen; i++)
    {   
        if (string[i] >= 'A' && string[i] <= 'Z')
        {   
            string[i] = string[i] + 32; 
        }   
    }    

    return string;
} 

static char *sqlkeys[STRS_MAX] = {0};

static size_t sqlkeys_len[STRS_MAX] ={0};

static void sqlkeys_show(void)
{
    int i;

    for (i=0; i<STRS_MAX; i++) {
        if(sqlkeys[i] && sqlkeys_len[i] > 0) {
            printf("index:%d len:[%d] sqlkeys[%s]\n",
                    i, sqlkeys_len[i], sqlkeys[i]);
        }
    }
}

static void sqlkeys_fini(void)
{
    int i;

    for (i = 0; i < STRS_MAX; i++) {
        if (sqlkeys[i]) {
            free(sqlkeys[i]);
            sqlkeys[i] = NULL;
        }
    }
}

static void sqlkeys_init(void)
{
    int i = 0;

#define STRS_SET_STR(x) \
    do {    \
        if (i < STRS_MAX) {    \
            sqlkeys[i] = (char *)malloc(strlen(#x) + 1);    \
            if (sqlkeys[i]) {   \
                strcpy(sqlkeys[i], #x);       \
                str_to_lower(sqlkeys[i], strlen(#x));   \
                sqlkeys_len[i++] = strlen(#x);   \
            }   \
        }   \
    } while(0);

    STRS_SET_STR(union);
    STRS_SET_STR(all);
    STRS_SET_STR(select);
    STRS_SET_STR(as);
    STRS_SET_STR(top);
    STRS_SET_STR(concat);
    STRS_SET_STR(join);
    STRS_SET_STR(left);
    STRS_SET_STR(right);
    STRS_SET_STR(from);
    STRS_SET_STR(where);
    STRS_SET_STR(on);
    STRS_SET_STR(like);
    STRS_SET_STR(between);
    STRS_SET_STR(insert);
    STRS_SET_STR(into);
    STRS_SET_STR(delete);
    STRS_SET_STR(update);
    STRS_SET_STR(drop);
    STRS_SET_STR(sleep);
    STRS_SET_STR(and);
    STRS_SET_STR(or);
    STRS_SET_STR(distinct);
    STRS_SET_STR(alter);
    STRS_SET_STR(create);
    STRS_SET_STR(trigger);
    STRS_SET_STR(set);
    STRS_SET_STR(declare);
    STRS_SET_STR(fetch);
    STRS_SET_STR(prepare);
    STRS_SET_STR(execute);
    STRS_SET_STR(describe);

#undef STRS_SET_STR
}
   
int find_str_casein_strs(char *sqlkeys[], size_t ksize, char *value, size_t vlen)
{
	char *string;     //字符串循环变量
	char *parValue;   //和value一样，只是易于回归
    int i, j;

    for (i = 0; i < ksize; i++) 
    {
        string = sqlkeys[i];
		parValue = value;

        if (string == NULL) 
        {
            break;
        }

        /* check length equal */
        if (sqlkeys_len[i] != vlen) 
        {
            continue;
        }

        /* check bytes equal */
        for (j = 0; j < vlen; j++) 
        {
            if (parValue[j] >= 'a' && parValue[j] <= 'z') {
                if (string[j] != parValue[j]) { 
                    break;
                }
                if (j == vlen - 1) {
                    /* compare over */
                    return 1;
                }
            } else if (parValue[j] >= 'A' && parValue[j] <= 'Z') {
                if (string[j] != parValue[j] + 32) {
                    break;
                }
                if (j == vlen - 1) {
                    /* compare over */
                    return 1;
                }
            } else {
                /* not sql key words */
                break;
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
	char *text = "She said some groups have shown willingness to conduct dialogue with the government AnD reiterated the priority is to end violence and restore order in Hong Kong as soon as possible";

	char payload[512] = {0};

	char *p = payload;

	long long st = get_time_now();

    int i, hit;

    /* init */
    sqlkeys_init();

    sqlkeys_show();

	for (i = 0; i < 1; i++) {
		strcpy(payload, text);
		p = strtok(payload, " ");
		while(p) {
            hit = find_str_casein_strs(sqlkeys, STRS_MAX, p, strlen(p));
            if (hit == 1) {
                printf("p=%s %d\n", p, hit);
            }
			p = strtok(NULL, " ");
		}
	}

	printf("i=%d use time:%llu(us)\n", i, get_time_now() - st);

    /* fini */
    sqlkeys_fini();

	return 0;
}

