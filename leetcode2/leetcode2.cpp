// leetcode2.cpp : 定义控制台应用程序的入口点。
// 单链表模拟大整数相加

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p = new ListNode(0);
		ListNode *ans = p;
		int flag = 0;
		int temp = 0;
		while (p1&&p2)
		{
			temp = p1->val + p2->val + flag;
			flag = 0;
			if (temp > 9)
			{
				temp -= 10;
				flag = 1;
			}
			p->val = temp;
			p1 = p1->next;
			p2 = p2->next;
			p->next = new ListNode(0);
			p = p->next;
		}

		temp = 0;
		while (p1)
		{
			temp = p1->val + flag;
			flag = 0;
			if (temp > 9)
			{
				temp -= 10;
				flag = 1;
			}
			p->val = temp;
			p->next = new ListNode(0);
			p = p->next;
			p1 = p1->next;
		}

		temp = 0;
		while (p2)
		{
			temp = p2->val + flag;
			flag = 0;
			if (temp > 9)
			{
				temp -= 10;
				flag = 1;
			}
			p->val = temp;
			p->next = new ListNode(0);
			p = p->next;
			p2 = p2->next;
		}

		if (flag == 1)
		{
			p->val = 1;
			return ans;
		}

		ListNode *pp = ans;
		while (pp)
		{
			if (pp->next->next==nullptr)
			{
				pp->next = nullptr;
				break;
			}
			pp = pp->next;
		}

		return ans;
	}
};

int main()
{
	Solution S;
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(8);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(0);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *ans=S.addTwoNumbers(l1, l2);
	while (ans)
	{
		cout << ans->val << endl;
		ans = ans->next;
	}

	system("pause");
	return 0;
}

