// leetcode167.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// �����������������ĺ͵����ض�ֵ�������±�
// ʹ��map����ÿ��ֵ���±�
// ������target-numbers[i]��Ϊ�ؼ��ִ���map�ҳ�ʼ��Ϊ-1�����жϵ�ʱ�����±��������findӦ�ÿ��Լӿ��ٶ�

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	map<int, int> m;
	vector<int> ans;
	for (int i = 0; i < numbers.size(); i++)
		m[numbers[i]] = i;
	for (int i = 0; i < numbers.size(); i++)
		if (m.find(target - numbers[i]) != m.end())
		{
			ans.push_back(i + 1);
			ans.push_back(m[target - numbers[i]] + 1);
			return ans;
		}
}


int main()
{
	vector<int> numbers = { 2, 7, 11, 15 };
	vector<int> ans = twoSum(numbers, 9);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

