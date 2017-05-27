// leetcode141.cpp : �������̨Ӧ�ó������ڵ㡣
// �жϵ������Ƿ��л�
// ���ֻ������������ͷ���һֱ��
// ��ĳ����㴦���next��ΪNULL˵���޻������next��Ϊ֮ǰĳ�����ĵ�ַ��˵���л�
// ���Կ��Խ��������Ľ���ַ���浽һ��set�У����в���
// ע���ڴ���setʱҪ����һ����ʱ����������set�еĵ�ַ������p�ĵ������ϸ��£��൱��û���µĵ�ַ����
// ֮ǰTLE�˺þþ�����Ϊ���ԭ��
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
		//�ս���next��Ϊ�յĵ�������޻�
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

