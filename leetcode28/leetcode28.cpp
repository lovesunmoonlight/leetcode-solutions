// leetcode28.cpp : �������̨Ӧ�ó������ڵ㡣
// �Ӵ�����
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

