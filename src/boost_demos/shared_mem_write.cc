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

//注意：在进程退出后依然可以读取共享内存...
int main()
{
    boost::interprocess::shared_memory_object shdmem(boost::interprocess::open_or_create, "Highscore", boost::interprocess::read_write); //alloc
    shdmem.truncate(1024); //set size
	boost::interprocess::mapped_region region(shdmem, boost::interprocess::read_write); //mapped
	std::memset(region.get_address(), 1, region.get_size()); // memset
	char *mem = static_cast<char*>(region.get_address());    // cast type
	std::strcpy(mem, "hello world"); //write

	cout << "sleep start..." << endl;
	this_thread::sleep_for(chrono::minutes(5));
	cout << "sleep over!" << endl;

	return 0;
}
