/****************************************************************************
@file:pthread.cpp 
@author:ebayboy@163.com 
@date:2019-09-30 18:01 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

using namespace std;

void *say_hello(void *args)
{
	/*
	pthread_detach(pthread_self());
	*/

	int *idx = (int *)args;
	cout << "thread[" << *idx <<"] hello Runoob!" << endl;

	return 0;
}

int main(int argc, char **argv)
{
	pthread_t tids[NUM_THREADS];
	int indexs[NUM_THREADS];

	for (int i = 0; i<NUM_THREADS; i++) {
		indexs[i] = i;
		int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&indexs[i]);
		/* pthread_create default  join thread, 
		 * wait to main recycle resourse */
		if (ret != 0) {
			cout << "pthread_create failed!" << ret << endl;
			exit(-1);
		}
	}

	for (int i = 0; i<NUM_THREADS; i++) {
		pthread_join(tids[i], NULL);
	}

	pthread_exit(0);
}

