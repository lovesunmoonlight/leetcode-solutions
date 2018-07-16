// leetcode747.cpp : �������̨Ӧ�ó������ڵ㡣
// �������е����ֵ
// ��Ҫ�����ֵ��С�������κ�Ԫ�ص�����
// ���򷵻�-1

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
	int dominantIndex(vector<int>& nums) {
		int len = nums.size();
		
		if (len == 0) //�߽�����
			return -1;

		int max = -1;
		int index = -1;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				index = i;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (i != index&&max < nums[i] * 2)
				return -1;
		}
		return index;
	}
};

template <size_t n>
void printArray(int (&a)[n])
{
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}

int main()
{
	vector<int> nums1 = { 3, 84};
	vector<int> nums2 = { 1, 2, 3, 4 };
	Solution S;
	int ans1 = S.dominantIndex(nums1);
	int ans2 = S.dominantIndex(nums2);
	cout << ans1 << endl << ans2 << endl;

	int a[5] = { 1,2,3,4,5 };
	printArray(a);

	system("pause");
	return 0;
}

