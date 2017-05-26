// leetcode28.cpp : 定义控制台应用程序的入口点。
// 子串查找
// Accepted

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int strStr(string haystack, string needle)
{
	int ans;
	if ((ans = haystack.find(needle)) != string::npos)
		return ans;
	return -1;
}

int main()
{
	string s1, s2;
	while (cin>>s1>>s2)
	{
		cout << strStr(s1, s2) << endl;
	}
	system("pause");
	return 0;
}

