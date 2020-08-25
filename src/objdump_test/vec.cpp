
#include <iostream>
#include <vector>

#include "lib.h"

int func_in_main(int a)
{
  std::cout << "a:" << a << std::endl;

  return a + 1;
}

int main()
{
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  print_vec(vec);
  print_int(vec.size());
  print_str((char *)"hello world!");

  int f_in = func_in_main(5);
  std::cout << "f_in:" << f_in << std::endl;

  return 0;
}

//编译：
////g++ -o vec vec.cpp
