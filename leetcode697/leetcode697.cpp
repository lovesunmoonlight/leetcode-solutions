// leetcode697.cpp : �������̨Ӧ�ó������ڵ㡣
// ��һ��������Ӵ���ʹ�ø��Ӵ���Ԫ�س��ֵ���������ԭ������ͬ
// ��ĳ��Ԫ�غ͸�Ԫ�س��ֵ������±걣�浽һ���������ӳ��

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::map;
using std::set;

class Solution {
public:
	/*int findShortestSubArray(vector<int>& nums) { //O(n^2)�ⷨ
		int count[50000] = {0}; //����
		int len = nums.size();
		for (int i = 0; i < len; i++)
			count[nums[i]]++;

		int max_count = 0;
		int max_number = -1;
		for (int i = 0; i < 50000; i++)
			if (count[i] >= max_count)
				max_count = count[i];

		vector<int> v;
		for (int i = 0; i < 50000; i++)
			if (count[i] == max_count)
				v.push_back(i);
		
		int min_distance = len;
		for (int i = 0; i < v.size(); i++)
		{
			int begin = 0;
			int end = len - 1;
			for (; nums[begin] != v[i]; begin++);
			for (; nums[end] != v[i]; end--);
			if (end - begin + 1 < min_distance)
				min_distance = end - begin + 1;
		}
		return min_distance;
	}*/

	int findShortestSubArray(vector<int>& nums) //O(n)�ⷨ
	{
		map<int, vector<int>> m;
		int len = nums.size();
		for (int i = 0; i < len; i++)
			m[nums[i]].push_back(i); //��ĳ��Ԫ�س��ֵ������±걣�浽һ������

		int max_count = 0;
		for (const auto &i : m)
			if (i.second.size() > max_count)
				max_count = i.second.size();

		int min_distance = len;
		for (const auto &i : m)
		{
			if (i.second.size() != max_count)
				continue;
			if (i.second[i.second.size() - 1] - i.second[0] + 1 < min_distance)
				min_distance = i.second[i.second.size() - 1] - i.second[0] + 1;
		}

		return min_distance;
	}
};

int main()
{
	vector<int> nums = { 1,3,2,2,3,1 };
	Solution S;
	cout << S.findShortestSubArray(nums) << endl;

	system("pause");
	return 0;
}

