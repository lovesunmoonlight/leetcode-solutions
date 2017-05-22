// biaodashi.cpp : �������̨Ӧ�ó������ڵ㡣
// �������leetcode�ϵģ�ֻ����������ʽ��ֵ

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
	//�Ȳ���������
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

	optr.push('#'); //���ʽ��ʼ��'#'
	int cnt = 0;
	char c = s[cnt];
		while (c != '#' || optr.top() != '#') //ջ��ֻʣ����'#'������ʱ����
		{
			if (op.find(c) == op.end()) //������������ջ
			{
				opnd.push(c);
				c = s[++cnt];
			}
			else
			{
				switch (Precede(optr.top(), c))
				{
					case '<': //ջ��Ԫ������Ȩ��
						optr.push(c);
						c = s[++cnt];
						break;
					case '=': //�����Ų�������һ�ַ�
						optr.pop();
						c = s[++cnt];
						break;
					case '>': //��ջ������������ջ
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

