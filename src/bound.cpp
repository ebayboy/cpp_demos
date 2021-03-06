
//sort && lower_bound && upper_bound
//lower_bound和upper_bound都是返回大于value的元素的位置

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

#include "common.h"

using namespace std;

#define DEBUG

static bool bound_cmp(int a, int b) 
{
	return  a < b;
}

int main(int argc, char **argv)
{
    vector<int> v = { 1, 3, 5,5, 5, 5, 7, 9 };
	std::sort(std::begin(v), std::end(v));
    SHOW_VEC(v);

    //返回第一个小于等于value的元素位置, v是有序的
    vector<int>::iterator it = std::lower_bound(std::begin(v), std::end(v), 5);
    cout << "lower_bound at index: " << it - std::begin(v) << endl;
    cout << "item: " << *it << endl;

    //返回第一个大于value的元素位置
    vector<int>::iterator it1 = std::upper_bound(std::begin(v), std::end(v), 5);
    cout << endl << "upper_bound at index: " << it1 - std::begin(v) << endl;
    cout << "item: " << *it1 << endl;

    //test_self_cmp
    vector<int> v1 = { 1, 3, 5,5, 5, 5, 7, 9 };
	std::sort(std::begin(v1), std::end(v1));
    SHOW_VEC(v1);

	cout << endl;


	// bound_cmp cmp里函数应该写的是小于运算的比较
    auto it2 = std::lower_bound(std::begin(v1), std::end(v1), 5, bound_cmp);
    auto it3 = std::upper_bound(std::begin(v1), std::end(v1), 5, bound_cmp);

	cout << endl << "lower_bound self func: " << it2 - std::begin(v1) << endl;
	cout << "item: " << *it2 << endl;

	cout << endl << "upper_bound self func: " << it3 - std::begin(v1) << endl;
	cout << "item: " << *it3 << endl;

    return 0;
}

