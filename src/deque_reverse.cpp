#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void print(int e)
{
    cout << "e:" << e << endl;
}

int main(int args, char **argv)
{
    deque<int> d;

    for (size_t i = 0; i < 10; i++)
    {
       d.push_back(i);
    }

    //find
    deque<int>::iterator pos1 =  std::find(d.begin(), d.end(), 3); //3 
    deque<int>::iterator pos2 =  std::find(d.begin(), d.end(), 8); //8


    deque<int>::reverse_iterator rpos1(pos1); // 1
    deque<int>::reverse_iterator rpos2(pos2); // 7

    cout << "next(pos1):" << *(std::next(pos1)) << endl;
    cout << "next(rpos1):" << *(std::next(rpos1)) << endl;

    cout << "pos1:" << *pos1 << endl;
    cout << "rpos1:" << *rpos1 << endl;  //

    for_each(rpos2, rpos1, print);

    return 0;
}

/*
pos1:3
next(pos1):4
rpos1:2
next(rpos1):1
e:7
e:6
e:5
e:4
e:3
*/
