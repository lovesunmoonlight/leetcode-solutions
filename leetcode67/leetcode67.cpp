// leetcode67.cpp : 定义控制台应用程序的入口点。
// 字符串模拟二进制加法
// 注意一点就是当前和可能为0,1,2,3中任意一个
// 可以采用%2来得到当前位的值，同时进位标志置为1
// Accepted

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

string addBinary(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int len1 = a.size();
	int len2 = b.size();
	int len = len1 < len2 ? len1 : len2;
	string ans;
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		int sum = a[i]-'0' + b[i]-'0' + flag;
		if (sum > 1)
		{
			sum %= 2;
			flag = 1;
		}
		else
			flag = 0;
		ans.push_back(sum + '0');
	}
	if (len1 > len2)
	{
		for (int i = len; i < len1; i++)
		{
			int sum = a[i] - '0' + flag;
			if (sum > 1)
			{
				sum %= 2;
				flag = 1;
			}
			else
				flag = 0;
			ans.push_back(sum + '0');
		}
	}
	else
	{
		for (int i = len; i < len2; i++)
		{
			int sum = b[i] - '0' + flag;
			if (sum > 1)
			{
				sum %= 2;
				flag = 1;
			}
			else
				flag = 0;
			ans.push_back(sum + '0');
		}
	}
	if (flag == 1)
		ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << addBinary(s1, s2) << endl;
	system("pause");
	return 0;
}

