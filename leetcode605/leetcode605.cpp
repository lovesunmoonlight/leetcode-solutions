// leetcode605.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	if (flowerbed.size() < 3)
		return false;
	int ans = 0;
	for (int i = 0; i < flowerbed.size() - 3;)
	{
		if (flowerbed[i] == 0&&flowerbed[i + 1] ==0&& flowerbed[i + 2] == 0)
		{
			ans++;
			i += 2;
		}
		else
			++i;
	}
	if (ans >= n)
		return true;
	return false;
}

int main()
{
	vector<int> s = { 1,0,0,0,1 };
	cout << canPlaceFlowers(s, 2) << endl;
	system("pause");
	return 0;
}

