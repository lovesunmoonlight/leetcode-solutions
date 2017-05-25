// leetcode21.cpp : �������̨Ӧ�ó������ڵ㡣
// �ϲ�������������
// Accepted

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
* Definition for singly-linked list.
**/ 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {} 
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//ĳ����Ϊ��
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int val;
		if (p1->val <= p2->val)
		{
			val = p1->val;
			p1 = p1->next;
		}
		else
		{
			val = p2->val;
			p2 = p2->next;
		}
		ListNode* ans=new ListNode(val);
		ListNode* p = ans;
		while (p1&&p2)
		{
			if (p1->val <= p2->val)
			{
				p->next = new ListNode(p1->val);
				p = p->next;
				p1 = p1->next;
			}
			else
			{
				p->next = new ListNode(p2->val);
				p = p->next;
				p2 = p2->next;
			}
		}
		//ʣ��ĳ�����Ĳ���
		if (p1)
		{
			while (p1)
			{
				p->next = new ListNode(p1->val);
				p = p->next;
				p1 = p1->next;

			}
		}
		if (p2)
		{
			while (p2)
			{
				p->next = new ListNode(p2->val);
				p = p->next;
				p2 = p2->next;

			}
		}
		return ans;

	}
};


int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(5);
	Solution S;
	ListNode* ans = S.mergeTwoLists(l1, l2);
	ListNode* p = ans;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

