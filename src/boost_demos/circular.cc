/*
 * =====================================================================================
 *
 *       Filename:  circular.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2020年09月24日 10时52分03秒
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
#include <cassert>

#include <boost/circular_buffer.hpp>

using namespace std;

#define DEBUG

int main(int argc, char **argv)
{

    boost::circular_buffer<int> cb(3);

    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);

    cb.push_back(4);
    cb.push_back(5);

    cb.pop_back();
    cb.pop_front();

//	static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");
	assert(cb[0] == 1);

    return 0;
}

