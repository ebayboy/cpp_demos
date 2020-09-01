
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Base {
  Base() 
  {
    cout << "base" << endl << endl;
  }
  int age;
};

struct Child : public Base {
  string name;
  Child() 
  {
    cout << "child" << endl << endl;
  }
};

int main( )
{
  Child cl;

  cout << "hello" << endl;


  return 0;
}
