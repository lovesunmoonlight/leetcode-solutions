// leetcode217.cpp : �������̨Ӧ�ó������ڵ㡣
// �ж��Ƿ����ظ�Ԫ��
// ��������������
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


bool containsDuplicate(vector<int>& nums)
{
	if (!nums.size())
		return false;
	sort(nums.begin(),nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
		if (nums[i] == nums[i + 1])
			return true;
	return false;
}


int main()
{
	vector<int> nums;
	int n;
	while (cin >> n)
		nums.push_back(n);
	if (containsDuplicate(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}

