// leetcode521.cpp : �������̨Ӧ�ó������ڵ㡣
// һ����ˮ�⣬��������ַ�����ͬ�򷵻����ĳ���
// ���򷵻�-1
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

