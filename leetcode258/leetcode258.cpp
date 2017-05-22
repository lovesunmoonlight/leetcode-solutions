// leetcode258.cpp : 定义控制台应用程序的入口点。
// 求各位数字之和，保证最后的和为一位数
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <numeric>

using namespace std;

int addDigits(int num)
{
	string s = to_string(num);
	int temp=num;
	while (s.size() > 1)
	{
		temp = accumulate(s.begin(), s.end(), -(int)s.size()*'0');
		s = to_string(temp);
	}
	return temp;
}

int main()
{
	int num;
	while (cin >> num)
		cout << addDigits(num) << endl;
	system("pause");
	return 0;
}

