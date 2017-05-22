// leetcode167.cpp : 定义控制台应用程序的入口点。
// Accepted
// 在数组中找两个数的和等于特定值，返回下标
// 使用map保存每个值的下标
// 将所有target-numbers[i]作为关键字存入map且初始化为-1，在判断的时候用下标操作代替find应该可以加快速度

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

