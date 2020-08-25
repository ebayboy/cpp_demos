
#include <iostream>
#include <vector>

void print_vec(const std::vector<int>& vec)
{
  std::cout << "print vec : ";
  size_t size = vec.size();
  for(size_t i = 0; i<size; i++)
    std::cout << vec[i] << "\t";
  std::cout << "\n";
}

void print_int(int i)
{
  std::cout<<"print_int : " << i << "\n";
}

void print_str(char* str)
{
  std::cout<<"print_str : " << str << "\n";
}


