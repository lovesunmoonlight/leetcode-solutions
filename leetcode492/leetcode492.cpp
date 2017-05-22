// leetcode492.cpp : 定义控制台应用程序的入口点。
// 寻找两个值相乘等于给定值
// 要求这两个值距离尽量小
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> constructRectangle(int area)
{
	vector<int> ans;
	int sq = (int)sqrt(area);
	for (int i = sq; i >=1; i--)
		if (area%i == 0)
		{
			ans.push_back(area / i);
			ans.push_back(i);
			return ans;
		}
}


int main()
{
	vector<int> ans;
	int area;
	while (cin >> area)
	{
		ans = constructRectangle(area);
		cout << ans[0] << " " << ans[1] << endl;
	}
    return 0;
}

