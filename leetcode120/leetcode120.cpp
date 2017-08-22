// leetcode120.cpp : 定义控制台应用程序的入口点。
// 贪心
// 每次选择当前节点cur的左儿子或右儿子中较小者
// 左儿子序号为cur，右儿子序号为cur+1
// 未AC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size(); //层数
		int ans = 0;
		int cur = 0; //当前行中的位置
		ans += triangle[0][0];
		for (int i = 0; i < len-1; i++)
		{
			if (triangle[i + 1][cur] < triangle[i + 1][cur + 1])
			{
				ans += triangle[i + 1][cur];
			}
			else
			{
				ans += triangle[i + 1][cur + 1];
				++cur;
			}
		}
		return ans;

	}
};


int main()
{
	Solution S;
	vector<vector<int>> v = { {2},{3,4},{6,5,7},{4,1,8,3} };
	int ans = S.minimumTotal(v);
	cout << ans << endl;
	system("pause");
	return 0;
}

