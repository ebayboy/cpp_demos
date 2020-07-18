
#ifndef _WIN32_WINNT
#include <thread>
#else
#include "lib/mingw-std-threads/mingw.thread.h"
#endif

#include <iostream>

using namespace std;

int main()
{
    //g++ test.cpp -o test.exe -std=c++11 -D _WIN32_WINNT=0x0601
    cout << "sleep 3 start " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "sleep over!" << endl;

    return 0;
}
