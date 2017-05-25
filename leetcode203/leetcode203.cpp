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
		//空结点或一个结点单独处理
		if (!head)
			return nullptr;
		if (head->next == nullptr&&head->val == val)
			return nullptr;
		if (head->next == nullptr&&head->val != val)
			return head;
		ListNode* p = head;
		while (p)
		{
			if (p->val == val)
			{
				remove(head, p);
			}
			p= p->next;
		}
		return head;
	}

	void remove(ListNode* &head,ListNode* q)
	{
		if (q == head)
			*head= *(head->next);
		ListNode* p = head;
		while (p != q)
		{
			if (p->next == q)
			{
				p->next = p->next->next;
				break;
			}
			p = p->next;
		}
	}
};


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(3);
	Solution S;
	head=S.removeElements(head, 1);
	ListNode* p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

