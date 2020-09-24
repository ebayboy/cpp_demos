#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

int main()
{
	boost::interprocess::shared_memory_object::remove("Highscore");
    boost::interprocess::managed_shared_memory managed_shm(boost::interprocess::open_or_create, "Highscore", 1024);

    int *arr = managed_shm.construct<int>("age")[10](99);

	//init arr
	for(size_t j = 0; j < 10; j++){
		arr[j] = j;
	}

	//get arr from shared mem by key
    std::pair<int*, std::size_t> p = managed_shm.find<int>("age");
	if (p.first) {
        std::cout << "first:" << *p.first << std::endl;
		std::cout << "size:" << p.second << std::endl;

		//output 
		int *parr = p.first;
		for (size_t i = 0; i < p.second; i++) {
			cout << i << ":" << parr[i] << endl;
		}
	}

	return 0;
}

