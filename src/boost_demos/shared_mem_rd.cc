/*
 * =====================================================================================
 *
 *       Filename:  shared_mem.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2020年09月24日 15时12分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <thread>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace std;
using namespace boost::interprocess;

int main()
{
    shared_memory_object shm(open_only, "Highscore", read_only); //open
    mapped_region region(shm, read_only); //map
    char *mem = static_cast<char *>(region.get_address()); //read

	cout << "mem:" <<  mem << endl;

    return 0;
}
