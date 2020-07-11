#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

void list_int()
{
	//用list容器处理整型数据
	//用创建一个名为listOne的list对象
	list<int> listOne;
	
	//声明i为迭代器
	list<int>::iterator i;
	
	//从前面向listOne容器中添加数据
	//2,1
	listOne.push_front(1);
	listOne.push_front(2);

	//从后面向listOne容器中添加数据
	//2,1,3,4
	listOne.push_back(3);
	listOne.push_back(4);

	//从前向后显示listOne中的数据
	cout << "front -> back: ";
	for (i = listOne.begin(); i != listOne.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;


	//声明ir为反迭代器
	list<int>::reverse_iterator ir;

	//从后向后显示listOne中的数据
	cout << "back -> front: ";
	for (ir = listOne.rbegin(); ir != listOne.rend(); ir++) {
		cout << *ir << " ";
	}
	cout << endl;
	
	//使用STL的accumulate(累加list所有元素)算法
	int result = std::accumulate(listOne.begin(), listOne.end(), 0);
	cout << "result:" << result << endl;
}

void list_char()
{
	//--------------------------
	//用list容器处理字符型数据
	//--------------------------
	
	//用LISTCHAR创建一个名为listOne的list对象
	list<char> lc;
	
	//声明i为迭代器
	list<char>::iterator i;
	
	//从前面向listTwo容器中添加数据
	//B A 
	lc.push_front('A');
	lc.push_front('B');

	//从后面向listTwo容器中添加数据
	//B A C D
	lc.push_back('C');
	lc.push_back('D');
	
	//从前向后显示listTwo中的数据
	cout << "front -> end: ";
	for (i = lc.begin(); i != lc.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	//从后向前显示listTwo中的数据
	list<char>::reverse_iterator ri;
	cout << "end -> front : ";
	for (ri = lc.rbegin(); ri != lc.rend(); ri++) {
		cout << *ri << " ";
	}
	cout << endl;

	//使用STL的max_element算法求listTwo中的最大元素并显示
	
	i = std::max_element(lc.begin(), lc.end());
	cout << "max_element: " << *i << endl;
}

int main()
{
	cout << "hello world!" << endl;

	list_int();

	list_char();

	return 0;
}
