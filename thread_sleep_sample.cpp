
#include <thread>
#include <iostream>

using namespace std;

int main()
{
    //g++ test.cpp -o test -std=c++11
    cout << "sleep 3 start " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "sleep over!" << endl;
}
