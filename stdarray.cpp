#include <iostream>
#include <array>

using namespace std;

int main()
{
	std::array<int, 5> arr = {1,2,3,4,5};

	for (auto i : arr) {
		cout << i << endl;
	}
	
	return 0;
}
