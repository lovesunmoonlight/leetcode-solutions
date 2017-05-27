// leetcode495.cpp : 定义控制台应用程序的入口点。
// 模拟题
// 在给定的n个不同时刻进行特定长度的持续攻击，求总的攻击时间
// 如果前一个时间点的攻击持续到了下一个时间点，则总的攻击时间为两时间点之间的距离
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int ans=0;
		if (timeSeries.size() == 0)
			return ans;
		for (int i = 0; i < timeSeries.size() - 1; i++)
		{
			if (timeSeries[i + 1] - timeSeries[i] >= duration)
				ans += duration;
			else
				ans += timeSeries[i + 1] - timeSeries[i];
		}
		return ans+duration;
	}
};


int main()
{
	vector<int> timeSerise;
	int duration;
	int n;
	int i = 2;
	while (i--)
	{
		cin >> n;
		timeSerise.push_back(n);
	}
	cin >> duration;
	Solution S;
	cout << S.findPoisonedDuration(timeSerise, duration)<<endl;
	system("pause");
	return 0;
}

