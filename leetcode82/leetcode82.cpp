// leetcode82.cpp : 定义控制台应用程序的入口点。
// WA

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		if (head == nullptr || head->next == nullptr)
			return head;
		
		//头部的相同结点
		if (p->next->val == p->val)
		{
			while ((p != nullptr&&p->next != nullptr)&&(p->val == p->next->val))
			{
				head = head->next->next;
				p = head;
			}
		}

		while (p)
		{
			if(p->next->val)
		}

	}
};


int main()
{
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next->next = new ListNode(5);
	Solution S;
	head=S.deleteDuplicates(head);
	ListNode* p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

