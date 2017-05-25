// leetcode160.cpp : 定义控制台应用程序的入口点。
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		decltype(headA) p1 = headA;
		decltype(headB) p2 = headB;
		//有一个为空
		if (!p1 || !p2)
			return nullptr;
		//两个相同列表
		if (p1 == p2)
			return p1;
		while (p1)
		{
			while (p2)
			{
				if (p1->next&&p1->next== p2)
					return p2;
				p2=p2->next;
			}
			p1=p1->next;
		}
		while (p2)
		{
			while (p1)
			{
				if (p2->next&&p2->next == p1)
					return p1;
				p1 = p1->next;
			}
			p2 = p2->next;
		}
		return nullptr;
	}
};

int main()
{
	ListNode* headA = new ListNode(1);
	//headA->next = new ListNode(2);
	ListNode* headB = headA;
	Solution S;
	ListNode* ans=S.getIntersectionNode(headA, headB);
	cout << ans->val << endl;
	system("pause");
	return 0;
}

