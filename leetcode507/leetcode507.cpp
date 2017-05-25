// leetcode507.cpp : 定义控制台应用程序的入口点。
// 数学题，数据量10^8求因子
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

bool checkPerfectNumber(int num)
{
	if (num == 1)
		return false;
	int sum = 1;
	for (int i = 2; i<(int)sqrt(num+0.0)+1; i++)
		if (num%i == 0)
			sum += i+num/i;
	return sum == num;
}


int main()
{
	for (int i = 1; i <= 100; i++)
		if (checkPerfectNumber(i))
			cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}

