#include <thread>
#include <iostream>
#include <vector>

using namespace std;


int tstart(const string& tname) {
  cout << "Thread test! " << tname << endl;
  return 0;
}

int main() 
{

  int sz = 3 ;
  vector<thread> ths(sz - 1);

  thread t1(tstart, "C++ 11 thread_1!");
  thread t2(tstart, "C++ 11 thread_2!");
  thread t3(tstart, "C++ 11 thread_3!");

  ths[0].swap(t1);
  ths[1].swap(t2);

#if 0
  cout << "current thread id: " << this_thread::get_id() << endl;
  cout << "before swap: "<< " thread_1 id: " << t1.get_id() << " thread_2 id: " << t2.get_id() << endl;

  t1.swap(t2);
  cout << "after swap: " << " thread_1 id: " << t1.get_id() << " thread_2 id: " << t2.get_id() << endl;
#endif

  t1.join();
  t2.join();
  t3.join();


  return 0;
}
