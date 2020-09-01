
#include <iostream>
#include <functional>
#include <exception>

using namespace std;

struct ExitCaller  {
  //构造函数
  //std::move()如果参数是右值， 则不改变；
  //如果参数为左值， 则转换为右值
  ExitCaller(std::function<void()> &&functor) : functor_(std::move(functor)) 
  {
    cout << "constructor..." << endl;
  }

  //析构函数
  ~ExitCaller() 
  { 
    cout << "destructor..." << endl;
    functor_(); 
  }

  private:
  std::function<void()> functor_;
};

void (*p)();

void Test()
{
  cout << "test..." << endl;
}

int main(int argc, char const* argv[])
{
  cout << "cl1:================" << endl;

  //右值引用
  ExitCaller cl(Test);

  cout << "cl2:================" << endl;

  //函数指针
  p = Test;

  ExitCaller cl2(p);

  return 0;
}
