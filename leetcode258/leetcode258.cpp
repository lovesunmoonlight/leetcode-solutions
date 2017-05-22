// leetcode258.cpp : �������̨Ӧ�ó������ڵ㡣
// ���λ����֮�ͣ���֤���ĺ�Ϊһλ��
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

