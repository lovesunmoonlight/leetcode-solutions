// leetcode415.cpp : 定义控制台应用程序的入口点。
// 大整数加法
// 注意要看最后进位标志是否为1
// 为1说明增加一个最高位1
// Accepted

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int len1 = num1.size();
	int len2 = num2.size();
	int len = len1 < len2 ? len1 : len2;
	int flag=0; //进位标志
	string ans;
	for (int i = 0; i < len; i++)
	{
		int sum = num1[i]-'0' + num2[i]-'0' + flag;
		if (sum >= 10)
		{
			sum -= 10;
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
			int sum = num1[i]-'0' + flag;
			if (sum >= 10)
			{
				sum -= 10;
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
			int sum = num2[i]-'0' + flag;
			if (sum >= 10)
			{
				sum -= 10;
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
	string num1, num2;
	while (cin >> num1 >> num2)
	{
		cout << addStrings(num1, num2)<<endl;
	}
	system("pause");
	return 0;
}

