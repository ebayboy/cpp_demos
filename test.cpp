
#include <string>  
#include <iostream>  
   
using namespace std;  

void testCols(string cols [])
{

    cout << sizeof(cols)/sizeof(string)<< endl;
}

int main()  
{  
    string cols[] = { "111", "222", "333"}; 

    cout << "size:" <<sizeof(cols) /sizeof(string) << endl;

    testCols(cols);

    return 0;  
}  