// leetcode9.cpp : 定义控制台应用程序的入口点。
// 判断整数是否回文
// Accepted

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isPalindrome(int x)
{
	string s = to_string(x);
	string p = s;
	reverse(s.begin(), s.end());
	return p == s;
}


int main()
{
	int n;
	while (cin >> n)
	{
		if (isPalindrome(n))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	system("pause");
	return 0;
}

