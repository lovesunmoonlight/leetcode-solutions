// leetcode400.cpp : 定义控制台应用程序的入口点。
// 未AC

#include "stdafx.h"
#include <string>
#include <iostream>

#define MAX (2>>10-1)

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		return s[n - 1] - '0';

	}
	Solution() :s(create()) {}

	string create()
	{
		string s;
		int cnt = 1;
		while (s.size() < 1000000000)
		{
			s += to_string(cnt);
			++cnt;
		}
		return s;
	}

private:
	string s;
};

int main()
{
	int n;
	Solution S;
	for (int i = 1; i < 100; i++)
		cout << S.findNthDigit(i)<<endl;
	system("pause");
	return 0;
}

