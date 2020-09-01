#include <iostream>
#include <vector>
struct Student{
    std::string name;
    int age;
};
int main()
{
    std::vector<Student> v{{"11", 11}, {"22", 22}, {"33", 33}};
    for (auto &&i : v) {
        decltype(i) tmp = i;
        std::cout << "age:" << tmp.age << " name:" << tmp.name << std::endl;
    }
    return 0;
}