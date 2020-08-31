#include <thread>
#include <iostream>

using namespace std;

int tstart(const string& tname) {
  cout << "Thread test! " << tname << endl;
  return 0;
}

int main() {
  thread t1(tstart, "C++ 11 thread_1!");
  thread t2(tstart, "C++ 11 thread_2!");

  cout << "current thread id: " << this_thread::get_id() << endl;
  cout << "before swap: "<< " thread_1 id: " << t1.get_id() << " thread_2 id: " << t2.get_id() << endl;

  t1.swap(t2);
  cout << "after swap: " << " thread_1 id: " << t1.get_id() << " thread_2 id: " << t2.get_id() << endl;

  t1.join();
  t2.join();
}
