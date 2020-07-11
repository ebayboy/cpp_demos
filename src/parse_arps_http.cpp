/****************************************************************************
@file:parse_arps_http.cpp 
@author:ebayboy@163.com 
@date:2019-10-08 15:16 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/* @in: id1=value1&id2=value2&id3=value3&id1=value11&id3=value33 */
int parse_args(const char *in, int ilen, char **out, size_t *olen) 
{
	/**
	 *	name1=value1&name2=value2&...
	 **/
	if (in == NULL || ilen == 0) {
		return -1;
	}

	char *tmp = (char *)malloc(ilen + 1);
	tmp[ilen] = '\0';
	memcpy(tmp, in, ilen);

	/* parse args */
	vector<string> pairslist;

	char *p = strtok(tmp, "&");
	while (p) {
		pairslist.push_back(p); 
		p = strtok(NULL, "&");  
	}

	if (tmp) {
		free(tmp);
		tmp = NULL;
	}

	if (pairslist.size() == 0) {
		return 0;
	}

	/* parse key-values */
	map <string, string> kvs;
	map <string, string>::iterator it_kv;
	for (size_t i=0; i < pairslist.size(); ++i ) {
		string name = pairslist[i].substr( 0, pairslist[i].find("=") );
		string value = pairslist[i].substr( pairslist[i].find("=") + 1 );

		it_kv = kvs.find(name);
		if (it_kv == kvs.end()) {
			kvs.insert(pair<string,string>(name,value));
		} else {
			it_kv->second += value;
		}
	}

	if (kvs.size() == 0) {
		return 0;
	}

	size_t len = 0;
	for (map<string,string>::iterator it = kvs.begin(); 
			it != kvs.end(); it++) {
		len += it->first.size();
		len += it->second.size();
		len += 2; /* & = */
	}

	if (len == 0) {
		return 0;
	}

	*out = (char *)malloc(len + 1);
	memset(*out, 0, len + 1);

	/* compose */
	for (map<string,string>::iterator it = kvs.begin(); it != kvs.end(); it++) {
		snprintf(*out + strlen(*out), len - strlen(*out), "%s%s=%s",
				it != kvs.begin() ? "&":"", 
				it->first.c_str(), 
				it->second.c_str());
	}

	*olen = strlen(*out);
	printf("out:[%s] olen:%lu\n", *out, *olen);

	return 0;
}

int main(int argc, char **argv)
{

	char *in = (char *)"id1=value1&id2=value2&id3=value3&id1=value11&id3=value33";
	char *out = NULL;
	size_t olen = 0;

	if (parse_args(in, strlen(in), &out, &olen) == -1) {
		fprintf(stderr, "Error:parse_args\n");
		return -1;
	}
	if (out) {
		free(out);
	}

	return 0;
}

