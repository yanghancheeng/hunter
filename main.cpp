#include <iostream>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include "leetcode.hpp"
using namespace std;



class Prt {
public:
	void operator()(long val) {
		cout << val << "   ";
	}
	void operator()(int val) {
		cout << val << "   ";
	}
	void operator()(string val) {
		cout << val << "   ";
	}

};


void foo() {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(30);
	nums.push_back(34);
	nums.push_back(5);
	nums.push_back(9);
	//nums.push_back();


	vector<string> vs;
	//vs.resize(nums.size());
	for_each(nums.begin(), nums.end(), [&](int val) {
		vs.push_back(to_string(val));
		});


	for_each(vs.begin(), vs.end(), Prt());
	cout << endl;
	sort(vs.begin(), vs.end(), [](string s1, string s2)->bool {
		s1.erase(remove(s1.begin(), s1.end(), '0'), s1.end());
		s2.erase(remove(s2.begin(), s2.end(), '0'), s2.end());
		return s1 > s2;
		});
	for_each(vs.begin(), vs.end(), Prt());
}

int main() {
	//foo();

	//s2.erase(std::remove(s2.begin(), s2.end(), '0'), s2.end());
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(0);
	nums.push_back(2);

	//[111311, 1113]

	Solution sol;
	string str = sol.largestNumber(nums);
	cout << str << endl;
	cout << endl; system("pause");
}