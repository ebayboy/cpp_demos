
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    vector <int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(2);
    array.push_back(3);

    for (auto it = array.begin(); it != array.end(); it++)
    {
        if (*it == 2) {
            array.erase(it);
            it--;
        }
    }

    for (auto & n : array) {
        cout << n << endl;
    }

    return 0;
}
