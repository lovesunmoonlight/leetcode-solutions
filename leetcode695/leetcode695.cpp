// leetcode695.cpp : �������̨Ӧ�ó������ڵ㡣
// BFS
// ����������ͨ���еĽ����Ŀ
// ����ÿ����ͨ��Ľ��������

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::deque;
using std::string;
using std::vector;

class Solution {
public:
	struct Point 
	{
		int x;
		int y;
		Point(int _x, int _y) :x(_x), y(_y) {}
	};

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		
		int a[51][51];
		int n = grid.size(); //����
		int m = grid[0].size(); //����

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = grid[i][j];

		int max = 0;

		bool visit[51][51];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				visit[i][j] = false;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				//��ÿһ����ͨ����һ��BFS��ͬʱ�������ֵ
				if (!visit[i][j] && a[i][j] != 0)
					BFS(a, n, m, i, j, visit, max);
			}

		return max;

	}

	//��(x,y)����Դ����bfs
	void BFS(int a[][51], int n, int m, int x, int y, bool visit[][51], int &max)
	{
		int cnt = 0;
		deque<Point> Q;
		Q.push_back(Point(x, y)); //��ʼ������
		visit[x][y] = true;

		while (!Q.empty())
		{
			Point temp = Q.front();
			Q.pop_front();
			int temp_x = temp.x;
			int temp_y = temp.y;

			++cnt;

			//����δ���ʵ��ھӽ�������
			if (temp_x - 1 >= 0 && temp_x - 1 < n&&temp_y >= 0 && temp_y < m)
			{
				if (!visit[temp_x - 1][temp_y] && a[temp_x - 1][temp_y] != 0)
				{
					Q.push_back(Point(temp_x - 1, temp_y));
					visit[temp_x - 1][temp_y] = true;
				}
			}

			if (temp_x + 1 >= 0 && temp_x + 1 < n&&temp_y >= 0 && temp_y < m)
			{
				if (!visit[temp_x + 1][temp_y] && a[temp_x + 1][temp_y] != 0)
				{
					Q.push_back(Point(temp_x + 1, temp_y));
					visit[temp_x + 1][temp_y] = true;
				}
			}

			if (temp_x >= 0 && temp_x < n&&temp_y - 1 >= 0 && temp_y - 1 < m)
			{
				if (!visit[temp_x][temp_y - 1] && a[temp_x][temp_y - 1] != 0)
				{
					Q.push_back(Point(temp_x, temp_y - 1));
					visit[temp_x][temp_y - 1] = true;
				}
			}

			if (temp_x >= 0 && temp_x < n&&temp_y + 1 >= 0 && temp_y + 1 < m)
			{
				if (!visit[temp_x][temp_y + 1] && a[temp_x][temp_y + 1] != 0)
				{
					Q.push_back(Point(temp_x, temp_y + 1));
					visit[temp_x][temp_y + 1] = true;
				}
			}

		}

		if (cnt >= max) //�������ֵ
			max = cnt;
	}
};

int main()
{
	Solution S;
	vector<vector<int>> v =
	{ {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	  {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
	  {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
	};

	cout << S.maxAreaOfIsland(v) << endl;
	system("pause");
	return 0;
}

