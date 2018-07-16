// leetcode674.cpp : �������̨Ӧ�ó������ڵ㡣
// ����������Ӵ�

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

class Solution {
public:
	/*int findLengthOfLCIS(vector<int>& nums) //ֱ�ӱ���
	{
		int len = nums.size();
		if (len <= 1)
			return len;

		int max_len = 1;
		for (int i = 0; i < len - 1;)
		{
			if (nums[i + 1] > nums[i])
			{
				int j = i + 1;
				int cnt = 1;
				while (j<len&&nums[j]>nums[j - 1])
				{
					j++;
					cnt++;
				}
				if (cnt > max_len)
					max_len = cnt;
				i = j;
			}
			else
				i++;
		}
		return max_len;
	}*/

	int findLengthOfLCIS(vector<int>& nums) //dp
	{
		int len = nums.size();
		if (len <= 1)
			return len;

		vector<int> dp; //d[i]�����Ե�i�����ֽ�β����������������ĳ���
		dp.resize(len);
		dp[0] = 1;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > nums[i - 1])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = 1;
		}

		int max_len = 1;
		for (auto i : dp) //�������е����ֵ
			if (i > max_len)
				max_len = i;

		return max_len;
	}
};

int main()
{
	vector<int> v1 = { 1,3,5,4,7 };
	vector<int> v2 = { 2,2,2,2,2 };
	Solution S;
	cout << S.findLengthOfLCIS(v1) << endl;
	cout << S.findLengthOfLCIS(v2) << endl;

	system("pause");
    return 0;
}

