
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class MyClass
{
public:
    MyClass(string name, int age) : name(name), age(age){};
    ~MyClass(){};
    friend ostream &operator<<(ostream &output, const MyClass &b)
    {
        cout << "name:" << b.name << endl;
        cout << "age:" << b.age << endl;
        return output;
    }
    void SetAge(int age)
    {
        this->age = age;
    }

    int GetAge()
    {
        return this->age;
    }

private:
    string name;
    int age;
};

int main(int args, char **argv)
{
    MyClass mc("fanpf", 30);
    cout << mc << endl;

    cout << "GetAge: " << mc.GetAge() << endl;

    return 0;
}
