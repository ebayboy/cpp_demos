/******************************************************************************************************
1、定时分执行一次、循环执行
2、单线程和多线程。主线程为单线程有多个定时器，如果每个定时器都用一个线程去实现，有些不太合理，也不易管理。
3、程序本来就是多线程，也会造成更大量的线程，另外定时器事件不太好解决。
4、借鉴boost利用最小堆实现
5、多线程的业务线程中不包含定时器管理器，单独启一个线程用来管理所有定时器，当时间触发时，向业务线程投递定时器消息即可。
******************************************************************************************************/

#ifndef MYTIMER_H
#define MYTIMER_H
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class TimerManager;

class MyTimer
{
public:
    enum class TimerType
    {
        ONCE = 0,
        CIRCLE = 1
    };

    MyTimer(TimerManager &manager);
    ~MyTimer();
    //启动一个定时器
    template <typename Func>
    void start(Func func, unsigned int ms, TimerType type);
    //终止一个定时器
    void stop();

private:
    //执行
    void on_timer(unsigned long long now);

private:
    friend class TimerManager;
    TimerManager &manager_;
    //调用函数，包括仿函数
    std::function<void(void)> m_timerfunc;
    TimerType timerType_;
    //间隔
    unsigned int m_nInterval;
    //过期
    unsigned long long m_nExpires;
    int m_nHeapIndex;
};

class TimerManager
{
public:
    //获取当前毫秒数
    static unsigned long long get_current_millisecs();
    //探测执行
    void detect_timers();

private:
    friend class MyTimer;
    //添加一个定时器
    void add_timer(MyTimer *timer);
    //移除一个定时器
    void remove_timer(MyTimer *timer);
    //定时上浮
    void up_heap(size_t index);
    //定时下沉
    void down_heap(size_t index);
    //交换两个timer索引
    void swap_heap(size_t index1, size_t index2);

private:
    struct HeapEntry
    {
        unsigned long long time;
        MyTimer *timer;
    };
    std::vector<HeapEntry> heap_;
};

template <typename Func>
inline void MyTimer::start(Func fun, unsigned int interval, TimerType timetpe)
{
    m_nInterval = interval;
    m_timerfunc = fun;
    m_nExpires = interval + TimerManager::get_current_millisecs();
    manager_.add_timer(this);
    timerType_ = timetpe;
}

#endif