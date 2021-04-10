#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty()) return "";
		else if (count(nums.begin(), nums.end(), 0) == nums.size()) return "0";
		else {
			//创建字符容器（便于字符排序），再将nums元素转为字符推入字符容器
			vector<string> vs;
			for (const int& num : nums) {
				vs.emplace_back(to_string(num));
			}
			//字符排序
			sort(vs.begin(), vs.end(), [](const string& s1, const string& s2)->bool {
				return s1 + s2 > s2 + s1;
				});
			//组装
			string ansStr;
			for (const string& s : vs) {
				ansStr += s;
			}
			return ansStr;
		}
	}
};