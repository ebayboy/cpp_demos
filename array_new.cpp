
#include <iostream>

using namespace std;

/* arr = { m1, m2 } */
static void test_arr_1(int m)
{
	int *arr = new int [m];

	delete [] arr;
}

/* 
 * arr = { m1, m2 }
 * m1 = { n1, n2, n3 } 
 **/
static void test_arr_2(int m, int n)
{
	int **arr;

	/* alloc one level node */
	arr = new int *[m];

	for (int i = 0; i< m; i++) {
		/* alloc tow level node */
		arr[i] = new int [n];
	}


	/* Del */
	for (int i = 0; i< m; i++) {
		delete [] arr[i];
	}

	delete [] arr;
}

/* 
 * arr[k][n][m];
 * arr = {m1, m2}
 * m1 = {n1, n2, n3}
 * n1 = {k1, k2, k3, k4}
 */
static void test_arr_3(int m, int n, int k)
{
	int ***arr;

	/* ============= ALLOC ============== */
	/* alloc one level node */
	arr = new int **[m];

	for (int i = 0; i < m; i++) {

		/* alloc tow level node */
		arr[i] = new int *[n];

		for (int j = 0; j < n; j++) {
			/* alloc three level node */
			arr[i][j] = new int [k];
		}
	}

	/* ============== DEL ============== */
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			/* delete three level nodes */
			delete [] arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		delete [] arr[i];
	}

	/* delete one level node */
	delete  [] arr;
}

int main() 
{
	/* arr[2] */
	test_arr_1(2); 

	/* arr[2, 3] */
	test_arr_2(2, 3);

	/* arr[2][3][4] */
	test_arr_3(2, 3, 4);

	return 0;
}
