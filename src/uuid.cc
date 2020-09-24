/*
 * =====================================================================================
 *
 *       Filename:  uuid.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2020年09月24日 09时25分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;

int main()
{
	boost::uuids::uuid a_uuid = boost::uuids::random_generator()(); 
	const string tmp_uuid = boost::uuids::to_string(a_uuid);
	cout << "str_uuid:" << tmp_uuid << endl;

    return 0;
}
