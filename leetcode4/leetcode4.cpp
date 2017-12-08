// leetcode4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int len = len1 + len2;
		int i = 0, j = i;
		vector<int> nums;
		while (i < len1&&j < len2)
		{
			if (nums1[i] < nums2[j])
			{
				nums.push_back(nums1[i]);
				++i;
			}
			else
			{
				nums.push_back(nums2[j]);
				++j;
			}
		}

		while (i < len1)
		{
			nums.push_back(nums1[i]);
			++i;
		}

		while (j < len2)
		{
			nums.push_back(nums2[j]);
			++j;
		}

		double ans;
		//cerr << len << endl;
		//for (auto i : nums)
			//cerr << i << endl;
		if (len % 2 == 1)
			ans = nums[(len - 1) / 2];
		else
			ans = (nums[len / 2] + nums[(len - 2) / 2]) / 2.0;
		return ans;

	}
};

int main()
{
	Solution S;
	vector<int> nums1 = { 1,3 };
	vector<int> nums2 = { 2 };
	cout<< S.findMedianSortedArrays(nums1, nums2) << endl;

	system("pause");
	return 0;
}

