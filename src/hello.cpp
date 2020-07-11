#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void  getCms(std::vector<string> &cmds)
{
	//HSET grp00_t.com_1590977400 1.1.1.1 "11|00|33|44|55|66|77"
	string tms[] = {"1590977400", "1590977460", "1590977520", "1590977580", "1590977640"};
	string split = "_";
	string grpid = "grp00";
	string vals[] = {"11|11|11|11|11|11", "22|22|22|22|22|22", "33|33|33|33|33|33", "44|44|44|44|44|44", "55|55|55|55|55|55"};

	//HSET grp00_t.com_1590977400 1.1.1.1 "11|00|33|44|55|66"
	std::vector<string> keys;
	std::vector<string> ips;

	//100 hosts
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < sizeof(tms)/sizeof(string); j++)
		{
			ostringstream oss;

			oss << "grp00_" << "t.com." << i << "_" << tms[j];
			keys.push_back(oss.str());
		}
	}

	//生成2000个ip地址
	//1-254.1.1.1-254
	int count = 2000;
	for (int k = 1; k < 254 && ips.size() < count; k++)
	{
		for (int m = 1; m < 254 && ips.size() < count; m++) {
			ostringstream oss;
			oss << k << ".1.1." << m;
			ips.push_back(oss.str());
		}
	}

	//遍历 keys ips vals
	for (auto k : keys) {
		for (auto ip : ips ) {
			for (auto val : vals) {
				//HSET grp00_t.com_1590977400 1.1.1.1 "11|00|33|44|55|66"
				string cmd = "HSET " + k + " " + ip + " \"" + val + "\"";
				cmds.push_back(cmd);
			}
		}
	}
}

int main()
{
	vector<string> cmds;

	/*
	getCms(cmds);
	cout <<"size:"<< cmds.size() << endl;
	*/

	cmds.push_back("1");
	cmds.push_back("2");
	cmds.push_back("3");
	cmds.push_back("4");

	for (int i = 0; i < cmds.size(); i++) {
		cout << cmds[i] << endl;
	}

	return 0;
}