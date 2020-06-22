#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

std::atomic_int scount(0);

//没有mutex多卖了两张票， 有锁的情况正常 
mutex  mtx;

int tickets= 100;

void selltickets()
{
    while(tickets > 0) {

        mtx.lock();

        cout << "售卖第" << tickets << "张票!" << endl;
        tickets--;
        scount++;

        mtx.unlock();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main(int argc, char const *argv[])
{
    thread t1(selltickets);
    thread t2(selltickets);
    thread t3(selltickets);

    t1.join();
    t2.join();
    t3.join();

    cout << "scount:" << scount << endl;

    return 0;
}
