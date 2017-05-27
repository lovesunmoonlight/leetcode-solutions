// leetcode349.cpp : 定义控制台应用程序的入口点。
// 求两个序列的交集
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> ans;
	set<int> a1(nums1.begin(), nums1.end());
	set<int> a2(nums2.begin(), nums2.end());
	for (auto i:a2)
	{
		if (a1.find(i) != a1.end())
			ans.push_back(i);
	}
	return ans;
}


int main()
{
	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	auto ans = intersection(nums1, nums2);
	for (auto i : ans)
		cout << i << endl;
	system("pause");	
	return 0;
}

