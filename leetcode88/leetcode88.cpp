// leetcode88.cpp : 定义控制台应用程序的入口点。
// Accepted
// 合并两个有序序列

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> nums3;
	while (m&&n)
	{
		if (nums1[m-1] > nums2[n-1])
		{
			nums3.push_back(nums1[m-1]);
			--m;
		}
		else if (nums1[m-1] < nums2[n-1])
		{
			nums3.push_back(nums2[n-1]);
			--n;
		}
		else
		{
			nums3.push_back(nums1[m-1]);
			--m;
			nums3.push_back(nums2[n-1]);
			--n;
		}
	}
	while (m)
	{
		nums3.push_back(nums1[m-1]);
		--m;
	}
	while (n)
	{
		nums3.push_back(nums2[n-1]);
		--n;
	}
	nums1 = vector<int>(nums3.crbegin(), nums3.crend());
}


int main()
{
	vector<int> nums1 = { 1,2,3 };
	vector<int> nums2 = { 4,5,6,6,7,8,8,9 };
	merge(nums1,3,nums2,8);
	for (auto i : nums1)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}

