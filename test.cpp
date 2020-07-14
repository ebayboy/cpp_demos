
#include <iostream>
#include <string>


using namespace std;

int main()
{
    size_t qps = 0;
    size_t ipPerLoop = qps/10;

    for(size_t n = 0; n < ipPerLoop; n++) {
        cout << "n:" << n << endl;
    }

    return 0;
}
