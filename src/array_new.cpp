#include <iostream>

using namespace std;

void test_arr1(size_t sz)
{
    int *arr;

    arr = new int[sz];

    delete[] arr;
}

void test_arr2(size_t a, size_t b)
{
    int **arr;

    //alloc
    arr = new int *[a];
    for (size_t i = 0; i < a; i++)
    {
        arr[i] = new int[b];
    }

    //delete
    for (size_t i = 0; i < a; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void test_arr3(size_t a, size_t b, size_t c)
{
    int ***arr;

    //申请一维数组空间
    arr = new int **[a];
    for (size_t i = 0; i < a; i++)
    {
        //申请二维
        arr[i] = new int *[b];
        for (size_t j = 0; j < b; j++)
        {
            //申请三维
            arr[i][j] = new int[c];
        }
    }

    //delete
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

int main(int argc, char const *argv[])
{
    /* array[2] */
    test_arr1(2);

    /* array[2,3] */
    test_arr2(2, 3);

    /* array [2,3,4] */
    test_arr3(2, 3, 4);

    return 0;
}
