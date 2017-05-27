// leetcode287.cpp : �������̨Ӧ�ó������ڵ㡣
// Ѱ���ظ�Ԫ��
// Accepted

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

int findDuplicate(vector<int>& nums)
{
	set<int> a;
	int ans;
	for (int i = 0; i < nums.size(); i++)
	{
		if (a.find(nums[i]) != a.end())
		{
			ans = nums[i];
			break;
		}
		a.insert(nums[i]);
	}
	return ans;
}


int main()
{
	vector<int> nums;
	int n;
	while (cin>>n)
	{
		nums.push_back(n);
	}
	auto ans = findDuplicate(nums);
	cout << ans<<endl;
	system("pause");
	return 0;
}

