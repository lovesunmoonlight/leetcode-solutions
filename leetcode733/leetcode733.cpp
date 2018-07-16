// leetcode733.cpp : 定义控制台应用程序的入口点。
// BFS
// 遍历一个四连通块

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::deque;

class Solution {
public:
	struct Point {
		int x;
		int y;
		Point(int _x, int _y) :x(_x), y(_y) {}
		Point() :x(0), y(0) {}
	};

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int R = image.size();
		int C = image[0].size();

		int oldColor = image[sr][sc];

		int a[51][51];
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				a[i][j] = image[i][j];

		bool visit[51][51];
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visit[i][j] = false;

		BFS(a, R, C, sr, sc, visit, oldColor, newColor);

		vector<vector<int>> ans;
		ans.resize(R);
		for (int i = 0; i < R; i++)
			ans[i].resize(C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				ans[i][j] = a[i][j];

		return ans;

	}

	//以(x,y)为源点做BFS
	void BFS(int a[][51], int R, int C, int x, int y, bool visit[][51], int oldColor, int newColor)
	{
		deque<Point> Q;
		Q.push_back(Point(x, y)); //初始化队列
		visit[x][y] = true;

		while (!Q.empty())
		{
			Point temp = Q.front();
			Q.pop_front();
			int temp_x = temp.x;
			int temp_y = temp.y;

			a[temp_x][temp_y] = newColor;

			//所有未访问的邻居结点入队列
			if (temp_x - 1 >= 0 && temp_x - 1 < R&&temp_y >= 0 && temp_y < C)
			{
				if (!visit[temp_x - 1][temp_y] && a[temp_x - 1][temp_y] == oldColor)
				{
					Q.push_back(Point(temp_x - 1, temp_y));
					visit[temp_x - 1][temp_y] = true;
				}
			}

			if (temp_x + 1 >= 0 && temp_x + 1 < R&&temp_y >= 0 && temp_y < C)
			{
				if (!visit[temp_x + 1][temp_y] && a[temp_x + 1][temp_y] == oldColor)
				{
					Q.push_back(Point(temp_x + 1, temp_y));
					visit[temp_x + 1][temp_y] = true;
				}
			}

			if (temp_x >= 0 && temp_x < R&&temp_y - 1 >= 0 && temp_y - 1 < C)
			{
				if (!visit[temp_x][temp_y - 1] && a[temp_x][temp_y - 1] == oldColor)
				{
					Q.push_back(Point(temp_x, temp_y - 1));
					visit[temp_x][temp_y - 1] = true;
				}
			}

			if (temp_x >= 0 && temp_x < R&&temp_y + 1 >= 0 && temp_y + 1 < C)
			{
				if (!visit[temp_x][temp_y + 1] && a[temp_x][temp_y + 1] == oldColor)
				{
					Q.push_back(Point(temp_x, temp_y + 1));
					visit[temp_x][temp_y + 1] = true;
				}
			}

		}
	}
};

int main()
{
	vector<vector<int>> image = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
	Solution S;
	int R = image.size();
	int C = image[0].size();

	vector<vector<int>> ans;
	ans.resize(R);
	for (int i = 0; i < R; i++)
		ans[i].resize(C);
	ans = S.floodFill(image, 1, 1, 2);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << ans[i][j];
		
		cout << endl;
	}

	system("pause");
	return 0;
}

