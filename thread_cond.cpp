#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>

using namespace std;

mutex mtx;
condition_variable cv;
vector<int> vec;

void producer()
{
    for (size_t i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mtx);

        while (!vec.empty())
        {
            cv.wait(lock);
        }

        vec.push_back(i);
        cout << "Produce product:" << i << endl;
        cv.notify_all();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer()
{
    for (size_t i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mtx);

        while(vec.empty())  
        {
            cv.wait(lock);
        }
        int temp = vec.back();
        vec.pop_back();
        cout << "Consume product:" << temp << endl;
        
        cv.notify_all();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
}

int main(int argc, char const *argv[])
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
