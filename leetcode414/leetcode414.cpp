// leetcode414.cpp : �������̨Ӧ�ó������ڵ㡣
// �������е�����������ظ�Ԫ��ֻ��һ�Σ�
// ��������ڵ������򷵻����ֵ
// ��ĿҪ��O(n)���Ӷȣ�����һ���󶥶�ʵ�֣����Ե�O(logn)
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int thirdMax(vector<int>& nums)
{
	priority_queue<int> ans;
	for (auto i : nums)
		ans.push(i);
	int max3,max2,max1;
	int max = ans.top();
	max1 = ans.top();
	while (!ans.empty()&&max1 == ans.top())
		ans.pop();

	if (!ans.empty())
	{
		max2 = ans.top();
		while (!ans.empty()&&max2 == ans.top())
			ans.pop();
	}
	
	if(!ans.empty())
		return max3 = ans.top();
	else
		return max;
}


int main()
{
	vector<int> nums = { 1,2 };
	cout<<thirdMax(nums);
	cout<< endl;
	system("pause");
	return 0;
}

