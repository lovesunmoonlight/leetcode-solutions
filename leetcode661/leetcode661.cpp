// leetcode661.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// �������ÿ����������Χ����ƽ��ֵ
// ��άvector v���Կ�����һ��v.size()*v[0].size()�ľ���

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int size = M.size();

		//����𰸾���
		vector<vector<int>> ans;
		ans.resize(size);
		for (int i = 0; i < size; i++)
			ans[i].resize(M[0].size());

		int x, y;
		int cnt = 0;
		for(x = 0; x < size; x++)
			for (y = 0; y < M[0].size(); y++)
			{
				
				int temp = 0;
				int cnt = 0;
				for(int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
					{
						//���Խ��
						if (x + i >= 0 && x + i < size && y + j >= 0 && y + j < M[0].size())
						{
							temp += M[x + i][y + j];
							++cnt;
						}
					}
				ans[x][y] = temp/cnt;
			}
		return ans;

	}
};

int main()
{
	vector<vector<int>> M = { {2, 3, 4},{5, 6, 7},{8, 9, 10},{11, 12, 13},{14, 15, 16} };
	Solution s;
	auto ans=s.imageSmoother(M);
	int size = ans.size();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < ans[0].size(); j++)
			cout << ans[i][j] << endl;
	system("pause");
	return 0;
}

