/****************************************************************************
@file:signal.cpp 
@author:ebayboy@163.com 
@date:2019-09-30 17:45 
@version 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;


void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << endl;

	exit(signum);
}

int main(int argc, char **argv)
{
	cout<<"start ok!"<<endl;

	signal(SIGINT, signalHandler);

	for (int i = 0;;i++) {
		cout << "i: "<< i << " going to sleep ..." << endl;
		if (i == 3) {
			raise(SIGINT);
		}
		sleep(1);
	}

	return 0;
}

