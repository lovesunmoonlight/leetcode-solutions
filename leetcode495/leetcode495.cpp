// leetcode495.cpp : �������̨Ӧ�ó������ڵ㡣
// ģ����
// �ڸ�����n����ͬʱ�̽����ض����ȵĳ������������ܵĹ���ʱ��
// ���ǰһ��ʱ���Ĺ�������������һ��ʱ��㣬���ܵĹ���ʱ��Ϊ��ʱ���֮��ľ���
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

