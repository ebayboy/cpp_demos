#include <iostream>

using namespace std;

void bubble_sort(int *arr, size_t len)
{
    int tmp;
    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,5,1,7,4,9,6,8,2};

    bubble_sort(arr, sizeof(arr) / sizeof(int));
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}