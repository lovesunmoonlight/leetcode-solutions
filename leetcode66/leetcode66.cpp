// leetcode66.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// ģ��ӷ���λ��ע�����λ������λ�����Ҫ����󵥶�����

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	if (digits.size() == 1 && digits[0] == 0)
		return vector<int>{1};

	vector<int> temp;
	int flag = 0;
	int len = digits.size();
	int cur = digits.back() + 1;
	digits.pop_back();
	if (cur >= 10)
	{
		flag = 1;
		cur -= 10;
	}
	temp.push_back(cur);
	
	while(!digits.empty())
	{
		int cur = digits.back()+flag;
		digits.pop_back();
		if (cur >= 10)
		{
			flag = 1;
			cur -= 10;
			temp.push_back(cur);
		}
		else
		{
			flag = 0;
			temp.push_back(cur);
		}

	}
	if (flag == 1)
		temp.push_back(1);

	vector<int> ans(temp.crbegin(), temp.crend());
	return ans;
}


int main()
{
	vector<int> nums = { 0,0 };
	vector<int> ans = plusOne(nums);
	for (auto i : ans)
		cout << i;
	cout << endl;
	system("pause");
	return 0;
}

