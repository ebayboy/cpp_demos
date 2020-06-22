
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
	std::vector<int> v { 1, 4, 3};

	for (auto i : v) cout << i <<" ";
	cout << endl;

	auto ret = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });
	cout << ret << endl;

	return 0;
}

