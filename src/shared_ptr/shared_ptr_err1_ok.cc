#include <iostream>
#include <memory>

using namespace std;

int main()
{
  shared_ptr<int> ptr1(new int);
  shared_ptr<int> ptr2(ptr1);

  cout<<ptr1.use_count()<<endl;
  cout<<ptr2.use_count()<<endl;

  return 0;
}
