// testtttt.cpp : 定义控制台应用程序的入口点。
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void moveZeroes(vector<int>& nums)
{
	int cnt = 0;
	vector<vector<int>::iterator> flag;
	for (auto i = nums.begin(); i != nums.end(); i++)
	{
		if (*i == 0)
		{
			flag.push_back(i);
			cnt++;
		}
	}

	while (!flag.empty())
	{
		nums.erase(flag.back());
		flag.pop_back();
	}

	for (int i = 0; i < cnt; i++)
		nums.push_back(0);


}

int main()
{
	vector<int> nums = {0,1,0,3,12};
	moveZeroes(nums);
	for (auto i : nums)
		cout << i << endl;
	system("pause");
	return 0;
}