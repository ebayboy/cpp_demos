
#include <iostream>

using namespace std;

namespace first_space {
	void func() {
		cout << "in first_space" << endl;
	}

	namespace third_space {
		void func () {
			cout << "in third name_space" << endl;
		}
	}
}

namespace second_space {
	void func() {
		cout << "in second_space" << endl;
	}
}

using namespace first_space::third_space;

int main()
{
	first_space::func();

	second_space::func();

	func();

	return 0;
}
