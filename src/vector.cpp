/* vector usage */

#include <iostream>
#include <vector>

using namespace std;

static void show_arr(vector <int> & arr) {
	int j;

	cout << "func:" << __func__ << endl;

	for (int j = 0; j < arr.size(); j++) {
		cout << arr[j] << endl;
	}

	cout << endl;
}

static void show_arr_with_it(vector <int> & arr) {
	cout << "func:" << __func__ << endl;

	vector <int>::iterator it;
	for (it = arr.begin(); it != arr.end(); it++) {
		cout << "*it: " << *it << endl;
	}

	cout << endl;
}

int main() {
	int a[4] = {1,2,3,4};

	vector <int> arr;

	/* 0. 添加元素到容器 */
	for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
		arr.push_back(a[i]);
	}

	/* 1. 通过下标删除元素 */
	for (int j = 0; j < arr.size(); j++) {
		if (arr[j] == 2) {
			cout << "del:" << arr[j] << endl;
			arr.erase(arr.begin() + j);
			break;
		}
		cout << arr[j] << endl;
	}

	/* 2. 通过下标展示 */
	show_arr(arr);

	/* 3. 通过迭代器删除 */
	vector <int>::iterator it;
	for (it = arr.begin(); it != arr.end(); it++) {
		if (*it == 3) {
			arr.erase(it);
		}
	}

	/* 4. 通过迭代器展示 */
	show_arr_with_it(arr);

	/* 5. insert 5 */
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 1) {
			arr.insert(arr.begin() + i, 5);
		}
	}
	show_arr_with_it(arr);

	return 0;
}
