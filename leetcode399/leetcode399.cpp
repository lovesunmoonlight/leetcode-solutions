// leetcode399.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <set>

using namespace std;

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{
	int len = values.size(); 
	set<string> s;
	for (int i = 0; i < len; i++)
	{
		s.insert(equations[i].first);
		s.insert(equations[i].second);
	}
	const int v = s.size();
	vector<vector<double>> m;
	for (int i = 0; i < len; i++)
	{
		m[equations[i].first][equations[i].second] = values[i];
	}
}


int main()
{
    return 0;
}

