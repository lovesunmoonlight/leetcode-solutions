// leetcode766.cpp : �������̨Ӧ�ó������ڵ㡣
// �ж�Toeplitz����

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

		for (int i = 0; i < row_cnt; i++) //��ʼ����Ԫ��δ����
			for (int j = 0; j < column_cnt; j++)
				flag[i][j] = false;

		bool ans = true;
		for (int i = 0; i < row_cnt; i++)
			for (int j = 0; j < column_cnt; j++)
			{
				if (flag[i][j] == false) //��ѡһ��δ���ʽ��
				{
					int temp = matrix[i][j];
					for (int k = 1; (i + k < row_cnt) && (j + k < column_cnt); k++)
					{
						flag[i + k][j + k] = true; //���ʸý��
						if (matrix[i + k][j + k] != temp) //�����·���Ѱ
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

