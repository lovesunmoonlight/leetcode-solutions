// leetcode53.cpp : �������̨Ӧ�ó������ڵ㡣
// ��������кͣ�DP��

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::set;
using std::queue;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();

		//�߽�����
		if (size == 1)
			return nums[0];
		if (size == 0)
			return 0;

		int flag = 0;
		int index = 0;
		int max_negative = nums[0];
		for (int i = 0; i < size; i++)
		{
			if (nums[i] > 0)
			{
				index = i;
				flag = 1; //��ʾ����������
				break;
			}
			if (nums[i] > max_negative)
				max_negative = nums[i];
		}

		if (!flag) //ȫ�������������������
			return max_negative;

		int *sum = new int[size]; //��ĳ��Ԫ�ؽ�β�������е���������к�
		sum[index] = nums[index];
		int cur = sum[index];
		for (int j = index + 1; j < size; j++) 
		{
			sum[j] = max(sum[j - 1] + nums[j], nums[j]);

			if (sum[j] > cur) //�������ֵ�����ڷ���
				cur = sum[j];
		}

		return cur;
	}
	
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<int> nums = { -2, -1};
	Solution S;
	cout << S.maxSubArray(nums) << endl;

	system("pause");
	return 0;
}

