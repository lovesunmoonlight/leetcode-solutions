// leetcode219.cpp : �������̨Ӧ�ó������ڵ㡣
// δAC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if (nums.size() == 1)
		return false;
	map<int, int> m;

	//ɨ��һ�飬��ʼ��Ϊ-1
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = -1;
	}

	//�ڶ���ɨ�裬�洢ÿ��ֵ��Ӧ���±꣬��ͬ��ֵֻ�洢һ��
	for (int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]] == -1)
			m[nums[i]] == i;
	}

	//������ɨ�裬�����û���±겻ͬ����ֵͬ��ע��Ҫ�ų�����
	for (int i = 0; i < nums.size(); i++)
	{
		if (i - m[nums[i]] <= k&&i-m[nums[i]]>=0)
			return true;
	}
	return false;
}


int main()
{
	vector<int> nums = { 1 };
	if (containsNearbyDuplicate(nums, 1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}

