// leetcode766.cpp : 定义控制台应用程序的入口点。
// 判断Toeplitz矩阵

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
	bool isToeplitzMatrix(vector<vector<int>>& matrix) 
	{
		int row_cnt = matrix.size();
		int column_cnt = matrix[0].size();

		vector<vector<bool>> flag;
		flag.resize(row_cnt);
		for (auto &i : flag)
			i.resize(column_cnt);

		for (int i = 0; i < row_cnt; i++) //初始化各元素未访问
			for (int j = 0; j < column_cnt; j++)
				flag[i][j] = false;

		bool ans = true;
		for (int i = 0; i < row_cnt; i++)
			for (int j = 0; j < column_cnt; j++)
			{
				if (flag[i][j] == false) //挑选一个未访问结点
				{
					int temp = matrix[i][j];
					for (int k = 1; (i + k < row_cnt) && (j + k < column_cnt); k++)
					{
						flag[i + k][j + k] = true; //访问该结点
						if (matrix[i + k][j + k] != temp) //向右下方搜寻
						{
							ans = false;
							return ans;
						}
					}
				}
			}

		return ans;
	}
};

int main()
{
	vector<vector<int>> v1 = { {1,2,3,4},{5,1,2,3},{9,5,1,2} };
	vector<vector<int>> v2 = { {1,2},{2,2} };
	Solution S;
	cout << S.isToeplitzMatrix(v1) << endl;
	cout << S.isToeplitzMatrix(v2) << endl;

	system("pause");
    return 0;
}

