/****************************************************************************
  @file:2_2.cpp 
  @author:ebayboy@163.com 
  @date:2019-11-18 16:54 
  @version: 1.0  
  @description: cpp file 
  @Copyright (c)  all right reserved 
 **************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define DEBUG 

static int get_hc_num(unsigned int n)
{
	if (n > 9)
	{
		return n/10 + get_hc_num(n);
	}

	return -1;
}

static map<int, int> m_nums;

static void show_map(map<int,int> *m)
{
	map<int,int>::iterator i;
	for (i = m->begin(); i != m->end(); i++)
	{
		cout << i->first << ":" << i->second << " ";
	}
	cout << endl;
}

static void map_init(map<int,int> *m)
{
	m->insert(std::pair<int, int>(0, 6));
	m->insert(std::pair<int, int>(1, 2));
	m->insert(std::pair<int, int>(2, 5));
	m->insert(std::pair<int, int>(3, 5));
	m->insert(std::pair<int, int>(4, 4));
	m->insert(std::pair<int, int>(5, 5));
	m->insert(std::pair<int, int>(6, 6));
	m->insert(std::pair<int, int>(7, 7));
	m->insert(std::pair<int, int>(8, 7));
	m->insert(std::pair<int, int>(9, 2));
}

static int get_num_count(unsigned int a)
{
	if (a > 9) {
		unsigned int tmp = a/10;
		unsigned int tmp2 = a - 10*(a/10);
		map<int,int>::iterator iter = m_nums.find(tmp);
		if (iter != m_nums.end()) {
			int ret2 = get_num_count(tmp2);
			if (ret2 > 0) {
				return iter->second + ret2;
			}
		} 
	} else {
		map<int,int>::iterator iter = m_nums.find(a);
		if (iter != m_nums.end()) {
			return iter->second;
		}
	}

	return -1;
}

#define MAX_NUM 24
#define OPT_NUM 2
#define OPT_EQU 2

int main(int argc, char **argv)
{
	unsigned int i, j;
	int max = MAX_NUM - OPT_NUM - OPT_EQU;
	int a, b;

	std::map<int, int> result;

	map_init(&m_nums);

	show_map(&m_nums);

	for (i = 1; ; i++) {
		a = get_num_count(i);
		if ( a == -1 || a > max) {
			break;
		}
		for (j = 1; ; j++) {
			b = get_num_count(j);
			if (b == -1) {
				break;
			}
			if (a + b == max) {
				result.insert(std::pair<int, int>(i, j));
			} else if (a + b > max) {
				break;
			}
		}
	}

	cout << "show result:" << endl;
	show_map(&result);

	return 0;
}

