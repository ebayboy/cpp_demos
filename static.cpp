
#include <iostream>

using namespace std;

/* static �ؼ��� */

static int count = 10;

void func(void);

int main()
{
	while(count--)
	{
		func();
	}
	
	return 0;
}

void func (void)
{
	static int i = 5;
	i++;
	
	cout << "i=" << i << endl;
	cout << "count=" << count << endl;
	
}
