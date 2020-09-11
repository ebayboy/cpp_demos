
#include <iostream>
#include <vector>

using namespace std;

class student {
  public:
  string name;
  int age;
  student() {}
  student(string s, int i): name(s), age(i) {}

  friend ostream &operator<<( ostream &output,  const student &D )
  { 
    output << "name : " << D.name << " age : " << D.age;

    return output;            
  }
};


int main()
{
  vector<student> stus;

  for (int i = 0; i < 10; i++) {
#if 1
      stus.emplace_back();
      stus.back().name = "rose";
      stus.back().age = 30;
#else
      stus.emplace_back("fanpf", i).age = 30;
#endif
  }

  for (auto&& var : stus) {
    cout << var << endl;
  }

  return 0;
}
