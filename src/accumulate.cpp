
//1. accumulate -- compute function

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	std::vector<bool> v { true, false, true};

	for (auto i : v) cout << i <<" ";
	cout << endl;

	auto ret = std::accumulate(v.begin(), v.end(), 1, [](bool a, bool b) { return a & b; });
	cout << ret << endl;

	cout << true << endl;

	return 0;
}

