// leetcode141.cpp : 定义控制台应用程序的入口点。
// 判断单链表是否有环
// 出现环的情况是沿着头结点一直走
// 到某个结点处如果next域为NULL说明无环，如果next域为之前某个结点的地址，说明有环
// 所以可以将遍历过的结点地址保存到一个set中，进行查找
// 注意在存入set时要借助一个临时变量，否则set中的地址会随着p的迭代不断更新，相当于没有新的地址加入
// 之前TLE了好久就是因为这个原因
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <set>
#include <memory>

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
	bool hasCycle(ListNode *head) {
		//空结点或next域为空的单个结点无环
		if (!head || !(head->next))
			return false;

		ListNode* p = head;
		set<ListNode*> S;
		ListNode* temp = head;
		S.insert(temp);
		while (p = p->next)
		{
			
			if (S.find(p)!=S.end())
				return true;
			if (p == nullptr)
				return false;
			ListNode* temp = p;
			S.insert(temp);
		}
		return false;

	}
};


int main()
{
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head;
	Solution s;
	if (s.hasCycle(head))
		cout << "There is a cycle." << endl;
	else
		cout << "There is not a cycle." << endl;
	decltype(head) p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
		if (p == head)
			break;
	}
	system("pause");
	return 0;
}

