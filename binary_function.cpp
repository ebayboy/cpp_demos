#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    string _stuName;
    float _stuScore;

public:
    Student() {}
    ~Student(void) {}
    Student(string stuName, float stuScore)
    {
        _stuName = stuName;
        _stuScore = stuScore;
    }

    //布尔运算符重载, left < right
    bool operator<(const Student &stu)
    {
        cout << "left: " << _stuScore << " right:" << stu._stuScore;
        return _stuScore < stu._stuScore;
    }

    //()运算符重载
    void operator()(const Student &stu)
    {
        cout << stu._stuName << "  " << stu._stuScore << endl;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Student s1;
    s1._stuName = "rose";
    s1._stuScore = 98;

    Student s2("fanpf", 100);

    //test operator<
    if (s1 < s2)
    {
        cout << "s2 < s1" << endl;
    }
    else
    {
        cout << "s2 > s1" << endl;
    }

    Student s3;
    //test operator()
    s3(s2);
    cout << "s3:" << s3._stuName << s3._stuScore << endl;

    return 0;
}
