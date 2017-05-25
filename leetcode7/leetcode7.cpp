// leetcode7.cpp : 定义控制台应用程序的入口点。
// 不知道题目要考什么
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x)
{
	return (int)sqrt(x + 0.0);
}
int main()
{
	int x;
	while (cin>>x)
	{
		cout << mySqrt(x) << endl;
	}
	system("pause");
	return 0;
}

