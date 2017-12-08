// leetcode3.cpp : 定义控制台应用程序的入口点。
// O(N^3)超时
// 滑动窗口O(N)复杂度

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.length();
		int i = 0, j = i;
		int maxlen = 0;
		set<char> m;
		while (i < len&&j < len)
		{
			if (m.find(s[j])==m.end())
			{
				m.insert(s[j++]);
				maxlen = max(maxlen, j - i);
			}
			else
			{
				m.erase(s[i++]);
			}
		}
		return maxlen;
	}
	int lengthOfLongestSubstring1(string s)
	{
		int len = s.length();
		int i = 0, j = i;
		int maxlen = 0;
		map<char, int> m;
		for (int j = 0, i = 0; j < len; j++)
		{
			if (m.find(s[j]) != m.end())
			{
				i = max(m[s[j]], i);
			}
			maxlen = max(maxlen, j - i + 1);
			m[s[j]]=j+1;
		}
		return maxlen;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	Solution S;
	string s;
	while (cin >> s)
		cout << S.lengthOfLongestSubstring1(s) << endl;
	return 0;
}

