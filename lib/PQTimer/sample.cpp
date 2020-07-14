
#ifndef MINGW_STDTHREADS_GENERATED_STDHEADERS
  #include <mingw.thread.h>
  #include <mingw.mutex.h>
  #include <mingw.condition_variable.h>
  #include <mingw.shared_mutex.h>
  #include <mingw.future.h>
#else
  #include <thread>
  #include <mutex>
  #include <condition_variable>
  #include <shared_mutex>
  #include <future>
#endif

#include <iostream>
#include <chrono>

#include "PQTimer.h"

using namespace std;

void test()
{
    cout << "test" << endl;
}

void temp_func()
{
    cout << "--------------" << endl;
}

int main()
{
    TimerManager manager;
    MyTimer timer1(manager);
    timer1.start(&test, 180, MyTimer::TimerType::CIRCLE);
    MyTimer timer2(manager);
    timer2.start(&temp_func, 200, MyTimer::TimerType::ONCE);
    MyTimer timer3(manager);
    timer3.start(&temp_func, 100, MyTimer::TimerType::ONCE);
    while (1)
    {
        this_thread::sleep_for(chrono::microseconds(200));
        manager.detect_timers();
    }
    getchar();
    getchar();
    return 0;
}