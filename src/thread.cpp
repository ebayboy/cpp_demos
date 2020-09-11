// thread example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <chrono>   //for time
#include <exception>
#include <vector>

using namespace std;

void foo()
{
  this_thread::sleep_for(chrono::seconds(1));
  cout << "foo" << endl;
}

void bar(int x)
{
  cout << "bar x:" << x << endl;
}

int main()
{
  try
  {
    std::vector<thread> tpool;

    tpool.emplace_back(foo);
    thread &t1 = tpool.back();
    t1.join();
  
    tpool.emplace_back(bar, 3);
    thread &t2 = tpool.back();
    t2.detach();

    this_thread::sleep_for(chrono::seconds(3));
  }
  catch (exception &ex)
  {
    cout << "ex:" << ex.what() << endl;
  }

  std::cout << "foo and bar completed.\n";

  return 0;
}

