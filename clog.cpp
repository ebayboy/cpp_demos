/* clog */
/* 
	ͨ����ЩСʵ���������޷����� cout��cerr �� clog �Ĳ��죬���ڱ�д��ִ�д��ͳ���ʱ��
	����֮��Ĳ���ͱ�÷ǳ����ԡ��������õı��ʵ���������ǣ�ʹ�� cerr ������ʾ������Ϣ��
	����������־��Ϣ��ʹ�� clog ��������� 
*/

#include <iostream>

using namespace std;


int main()
{
	char str[] = "Unable to read ... ";
	
	clog << "Error message: " << str << endl;	
	
	return 0;
}
