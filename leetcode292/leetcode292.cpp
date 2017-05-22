// leetcode292.cpp : 定义控制台应用程序的入口点。
// 巴什博弈，两人轮流从n个石子中每次取至多m个
// 最后取完者获胜
// 必胜态是取完之后给对手剩下m+1的倍数个石子
// 因而n如果是m的倍数则必输
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

bool canWinNim(int n) 
{
	if (n%4==0)
		return false;
	return true;
}


int main()
{
	system("pause");
	return 0;
}

