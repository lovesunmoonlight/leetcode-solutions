// leetcode7.cpp : �������̨Ӧ�ó������ڵ㡣
// ��֪����ĿҪ��ʲô
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

