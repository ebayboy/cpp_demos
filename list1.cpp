#include <iostream>
#include <list>

using namespace std;

void list_int()
{
	//用list容器处理整型数据
	//用创建一个名为listOne的list对象
	list<int> listOne;
	
	//声明i为迭代器
	list<int>::iterator i;
	
	//从前面向listOne容器中添加数据
	listOne.push_front(1);
	listOne.push_front(2);

	//从后面向listOne容器中添加数据
	listOne.push_back(3);
	listOne.push_back(4);

	//从前向后显示listOne中的数据
	
	//从后向后显示listOne中的数据
	
	//使用STL的accumulate(累加list所有元素)算法
}

void list_char()
{
	//--------------------------
	//用list容器处理字符型数据
	//--------------------------
	
	//用LISTCHAR创建一个名为listOne的list对象
	
	//声明i为迭代器
	
	//从前面向listTwo容器中添加数据
	
	//从后面向listTwo容器中添加数据
	
	//从前向后显示listTwo中的数据
	
	//使用STL的max_element算法求listTwo中的最大元素并显示
}

int main()
{
	cout << "hello world!" << endl;

	list_int();

	list_char();

	return 0;
}
