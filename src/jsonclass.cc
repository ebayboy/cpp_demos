#include <iostream>
#include <exception>
#include <string>

using namespace std;

namespace ns {
  class person {
    private:
      std::string name;
      std::string address;
      int age;
      public:
      person(string name, string address, int age) : name(name), address(address), age(age) {}
  };
}

int main(int argc, char const* argv[])
{
  ns::person p = {"Ned Flanders", "744 Evergreen Terrace", 60};
  string s1 = "hello";
  string s2 = "hello";

  if (s1 == s2) {
      cout << "eq" << endl;
  } else {
      cout << "ne" << endl;
  }



  return 0;
}
pari