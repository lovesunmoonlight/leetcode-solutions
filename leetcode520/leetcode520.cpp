// leetcode520.cpp : 定义控制台应用程序的入口点。
// 判断字符串是否合法
// 全小写，全大写或首字母大写属于合法
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

bool detectCapitalUse(string word)
{
	int size = word.size();
	if (word[0] >= 'A'&&word[0] <= 'Z')
	{
		int flag1 = 0;
		int flag2 = 0;
		for (int i = 1; i < size; i++)
		{
			if (word[i] >= 'a'&&word[i] <= 'z')
				++flag1;
			else
				++flag2;
		}
		if (flag1 == size - 1)
			return true;
		else if (flag2 == size - 1)
			return true;
		else
			return false;
	}
	else if (word[0] >= 'a'&&word[0] <= 'z')
	{
		int flag1 = 0;
		for (int i = 1; i < size; i++)
		{
			if (word[i] >= 'a'&&word[i] <= 'z')
				++flag1;
			else
				return false;
		}
		if (flag1 == size-1)
			return true;
	}
	return false;
}

int main()
{
	
	string s;
	while (cin >> s)
	{
		if (detectCapitalUse(s))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	system("pause");
	return 0;
}

