// leetcode830.cpp : 定义控制台应用程序的入口点。
// 统计一个字符串中，连续出现三次以上的字符的首尾位置

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::string;

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S)
	{
		int len = S.length();
		if (len < 3)
			return vector<vector<int>>();

		vector<vector<int>> ans;
		for (int i = 0; i < len - 1;)
		{
			if (S[i] == S[i + 1])
			{
				int cnt = 1;
				int j = i + 1;
				while (j < len&&S[j] == S[i])
				{
					j++;
					cnt++;
				}
				if (cnt >= 3)
					ans.push_back(vector<int>{i, j - 1});

				i = j;
			}
			else
				i++;
		}
		return ans;
	}
};

int main()
{
	string s = "abcdddeeeeaabbbcd";
	Solution S;
	auto ans = S.largeGroupPositions(s);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}	

	system("pause");
    return 0;
}

