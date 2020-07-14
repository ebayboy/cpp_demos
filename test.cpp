
#include <cstdio>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/* 1265222655.591(ms) */
string getCurrentTime()
{
    struct timeval tv;
    stringstream ss;

    gettimeofday(&tv, NULL);
    long sec  = tv.tv_sec *1000 + tv.tv_usec / 1000;
    long usec = tv.tv_usec % 1000;


    ss << sec << "." << usec;

    return ss.str();
}

int main()
{
    cout << "time:" << getCurrentTime() << endl;

    return 0;
}
