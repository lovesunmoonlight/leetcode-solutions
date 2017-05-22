// leetcode442.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// �ҵ������г������ε���������map�����ж��Ƿ��γ���
// mapֵ��ʼ��Ϊ-1
// ��һ��ɨ�赽ĳ��ֵʱ��mapֵ����Ϊ�±�
// �ڶ���ɨ�赽���ֵ��ʱ����mapֵ�Ƿ�Ϊ-1������˵���ǵڶ��γ�����
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

vector<int> findDuplicates(vector<int>& nums)
{
	vector<int> ans;
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = -1;
	}
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]] == -1)
			m[nums[i]] = i;
		else
			ans.push_back(nums[i]);
	}
	return ans;
}


int main()
{
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> ans = findDuplicates(nums);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

