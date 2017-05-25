// leetcode83.cpp : 定义控制台应用程序的入口点。
// 删除单链表中的重复元素
// 通常这种情况给定的都是有序的序列
// Accepted

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
	ListNode* deleteDuplicates(ListNode* head) {
		decltype(head) p = head;
		//只有0或1个结点直接返回
		if (!p||!(p->next))
			return p;

		while (p)
		{
			//注意检查p的下个结点是否越界
			if ((p->next)&& (p->val == p->next->val))
			{
				ListNode* q = p->next;
				//找到第一个不相等的结点
				while (q&&(q->val == p->val))
					q = q->next;
				//跳过这些相等的结点
				p->next = q;
			}
			p = p->next;
		}
		return head;

	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	decltype(head) p = head;
	cout << "Before:" << endl;
	while (p)
	{
		cout << p->val<<endl;
		p = p->next;
	}
	Solution s;
	p=s.deleteDuplicates(head);
	cout << "After:" << endl;
	while (p)
	{
		cout << p->val<<endl;
		p = p->next;
	}

	system("pause");
	return 0;
}

