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
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		
		//某一表为空
		if (!headA || !headB)
			return nullptr;

		while (p1)
		{
			while (p2)
			{
				if (p1 == p2)
					return p1;
				p2++;
			}
			p1++;
		}


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

