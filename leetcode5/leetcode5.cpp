// leetcode5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		int i = 0, j = i;
		int maxlen = 0;
		while (i < len&&j < len)
		{
			if (s[j] != s[i])
			{
				++i;
			}
			else
			{

			}
		}

	}
};

int main()
{
    return 0;
}

