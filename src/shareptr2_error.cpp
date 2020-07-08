
#include <iostream>
#include <memory>

//shareptr的错误用法
//https://blog.csdn.net/QIANGWEIYUAN/article/details/88973735

using namespace std;

class A
{

	public:
		A():mptr(new int) 
	{

		cout << "A()" << endl;
	}
		~A()
		{

			cout << "~A()" << endl;
			delete mptr; 
			mptr = nullptr;
		}
	private:
		int *mptr;
};
int main()
{

	A *p = new A(); // 裸指针指向堆上的对象

	shared_ptr<A> ptr1(p);// 用shared_ptr智能指针管理指针p指向的对象
	shared_ptr<A> ptr2(p);// 用shared_ptr智能指针管理指针p指向的对象
	// 下面两次打印都是1，因此同一个new A()被析构两次，逻辑错误
	cout << ptr1.use_count() << endl; 
	cout << ptr2.use_count() << endl;

	return 0;
}

