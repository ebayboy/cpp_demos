
// vector && binary_search

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	vector<int> v = {1,2,3,4,5};

	bool it = std::binary_search(std::begin(v), std::end(v), 5);
	cout << it << endl;

	return 0;
}

