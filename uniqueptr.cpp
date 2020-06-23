#include <iostream>
#include <string>
#include <memory> //used in linux

using namespace std;

int main(int argc, char const *argv[])
{
	unique_ptr<string> upt(new string("lvlv"));
	//unique_ptr<string> upt1(upt);	//编译出错，已禁止拷贝
	//unique_ptr<string> upt1=upt;	//编译出错，已禁止拷贝
	unique_ptr<string> upt1=std::move(upt);  //控制权限转移

    return 0;
}

