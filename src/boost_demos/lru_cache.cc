/*
 * =====================================================================================
 *
 *       Filename:  lru_cache.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月24日 16时40分50秒
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

#include <boost/compute/detail/lru_cache.hpp>

using namespace std;
using namespace boost::compute::detail;

int main(int argc, char **argv)
{
	lru_cache<string, int> lc(3);

	lc.insert("fanpf", 37);
	lc.insert("rose", 33);
	lc.insert("fanyf", 35);
		
	boost::optional<int>  opt_fpf = lc.get("fanpf");
	lc.insert("11", 35); //fanpf lose
	if(lc.contains("fanpf")){
		cout << "ok!" << endl;
	} else {
		cout << "not contain!" << endl;
		exit(1);
	}

#if 0
	assert(lc.contains("fanpf"));
	lc.insert("11", 35); //fanpf lose
	assert(!lc.contains("fanpf"));
#endif
		
	boost::optional<int>  opt_age = lc.get("1rose");

	if (lc.contains("rose")) {
		boost::optional<int>  opt_age = lc.get("rose");
		cout << "rose age:" << opt_age.get() << endl;
	}

	return 0;
}

