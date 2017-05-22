// leetcode521.cpp : 定义控制台应用程序的入口点。
// 一道大水题，如果两个字符串不同则返回最大的长度
// 否则返回-1
// Accepted

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int findLUSlength(string a, string b)
{
	if (a == b)
		return -1;
	return a.size() > b.size() ? a.size() : b.size();
}

int main()
{
	system("pause");
	return 0;
}

