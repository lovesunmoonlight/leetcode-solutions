// leetcode328.cpp : 定义控制台应用程序的入口点。
// 将链表的奇数位置结点放在偶数结点之前
// 这个参考了Solution里面大神的做法，很巧妙
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
* Definition for singly-linked list.
* */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		//判空
		if (!head||!head->next)
			return head;

		//由于题目要求O(1)空间复杂度，奇数位置头结点直接默认为原来链表的头结点
		ListNode* odditerator = head; //奇数位置结点迭代器从头结点开始
		ListNode* evenhead = head->next; //偶数位置头结点
		ListNode* eveniterator = evenhead; //偶数位置结点迭代器
		//判断偶数位置即可，偶数位置合法则它前面的奇数位置一定不会越界
		while (eveniterator&&eveniterator->next)
		{
			odditerator->next = odditerator->next->next;
			eveniterator->next = eveniterator->next->next;
			odditerator = odditerator->next;
			eveniterator = eveniterator->next;
		}
		odditerator->next = evenhead;
		return head;

	}
};

int main()
{
	ListNode* head = new ListNode(1);
	int i = 2;
	ListNode* p = head;
	while (i<=7)
	{
		p->next = new ListNode(i);
		p = p->next;
		++i;
	}
	p = head;
	cout << "Before:" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	Solution S;
	head = S.oddEvenList(head);
	p = head;
	cout << "After:" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

