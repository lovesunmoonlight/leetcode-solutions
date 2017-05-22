// leetcode561.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// ÿ��һ��Ԫ��ȡֵ���

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arrayPairSum(vector<int>& nums)
{
	int ans=0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2)
		ans += nums[i];
	return ans;
}


int main()
{
	vector<int> nums = { 1,2,3,4 };
	cout << arrayPairSum(nums) << endl;
	system("pause");
	return 0;
}

