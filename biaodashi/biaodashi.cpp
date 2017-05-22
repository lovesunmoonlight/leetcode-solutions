// biaodashi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char Precede(char theta1, char theta2)
{
	if (theta1 == '+'||theta1=='-')
	{
		if (theta2 == '+' || theta2 == '-' || theta2 == ')' || theta2 == '#')
			return '>';
		else
			return '<';
	}
	if (theta1 == '*' || theta1 == '/')
	{
		if (theta2 == '(')
			return '<';
		else
			return '>';
	}
	//先不考虑括号
	/*if (theta1 == '(')
	{
		if (theta2 == '+' || theta2 == '-' || theta2 == '*' || theta2 == '/' || theta2 == '(')
			return '<';
		if (theta2 == ')')
			return '=';
	}
	if (theta1 == ')')
	{
		return '>';
	}*/
	if (theta1 == '#')
	{
		if (theta2 == '#')
			return '=';
		else
			return '<';
	}
}

int Operate(int a, char opt, char b)
{
	switch (opt)
	{
		case '+':
			return a + b;
			break;
		case '-' :
			return a - b;
			break;
		case '*' :
			return a*b;
			break;
		case '/':
			return a / b;
			break;
	}
}

int solve(string& s)
{
	stack<char> optr;
	stack<int> opnd;
	set<char> op= {'+', '-', '*', '/', '(', ')', '#'};

	optr.push('#'); //表达式起始符'#'
	int cnt = 0;
	char c = s[cnt];
		while (c != '#' || optr.top() != '#') //栈中只剩两个'#'操作符时结束
		{
			if (op.find(c) == op.end()) //不是运算符则进栈
			{
				opnd.push(c);
				c = s[++cnt];
			}
			else
			{
				switch (Precede(optr.top(), c))
				{
					case '<': //栈顶元素优先权低
						optr.push(c);
						c = s[++cnt];
						break;
					case '=': //脱括号并接收下一字符
						optr.pop();
						c = s[++cnt];
						break;
					case '>': //退栈并将运算结果入栈
						char opt = optr.top();
						optr.pop();
						int a = opnd.top();
						opnd.pop();
						int b = opnd.top();
						opnd.pop();
						opnd.push(Operate(a, opt, b));
						break;

				}


			}
		}


	return opnd.top();
}

int main()
{
	string s;
	while (cin >> s)
	{
		s += '#';
		cout << solve(s) << endl;
	}
	system("pause");
	return 0;
}

