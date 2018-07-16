// leetcode867.cpp : 定义控制台应用程序的入口点。
// 矩阵转置

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		if (A.size() == 0 || A[0].size() == 0)
			return vector<vector<int>>();
		
		int row_cnt = A.size();
		int column_cnt = A[0].size();
		vector<vector<int>> ans;
		ans.resize(column_cnt);
		for (auto &i : ans)
			i.resize(row_cnt);
		
		for (int i = 0; i < row_cnt; i++)
			for (int j = 0; j < column_cnt; j++)
				ans[j][i] = A[i][j];

		return ans;
	}
};

int main()
{
	vector<vector<int>> v1 = { { 1,2,3 },{ 4,5,6 } };
	Solution S;
	auto ans = S.transpose(v1);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	system("pause");
    return 0;
}

