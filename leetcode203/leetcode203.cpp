// leetcode203.cpp : 定义控制台应用程序的入口点。
// WA

#include "stdafx.h"
#include <iostream>
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
	ListNode* removeElements(ListNode* head, int val) {
		//空表
		if (!head)
			return head;

		//单个结点
		if (head->next == nullptr)
		{
			if (val == head->val)
				return nullptr;
			else
				return head;
		}

		//删除前面连续几个与给定值相同的结点
		while (head&&val == head->val)
		{
			head = head->next;
		}
		
		ListNode* p = head;
		while (p&&p->next)
		{
			if (val == p->next->val)
			{
				p->next = p->next->next;
			}
			else
				p = p->next;
		}

		return head;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	/*head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next = new ListNode(6);*/
	ListNode* p = head;
	cout << "before:" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	Solution S;
	head=S.removeElements(head, 2);
	cout << "after:" << endl;
	p = head;
	while (p)
	{
		cout << p->val<<endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

