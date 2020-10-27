#include <QtCore/QCoreApplication>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/*
题目：一个链表，奇数位升序偶数位降序，让链表变成升序的
比如： 1 8 3 6 5 4 7 2 9 ，最后输出 1 2 3 4 5 6 7 8 9
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

ListNode* constructList(int* a, int size)
{
	ListNode* head = new ListNode(0);
	ListNode* h = head;
	for (size_t i = 0; i < size; i++)
	{
		h->next = new ListNode(a[i]);
		h = h->next;
	}
	return head->next;
}

void splitList(ListNode* head, ListNode* even, ListNode* odd)
{
	ListNode* e = even; //奇数
	ListNode* o = odd;   //偶数

	int index = 0;
	while (head)
	{
		if (index%2 == 0)
		{
			e->next = new ListNode(head->val);
			e = e->next;
		}
		else {
			o->next = new ListNode(head->val);
			o = o->next;
		}
		index++;
		head = head->next;
	}
}
ListNode* reverseList(ListNode* head)
{
	ListNode*  reverhead = nullptr;
	while (head)
	{
		ListNode* p = head->next;
		head->next = reverhead;
		reverhead = head;
		head = p;
	}
	return reverhead;
}
ListNode* mergeList(ListNode* h1, ListNode* h2)
{
	ListNode* preHead = new ListNode(-1);
	ListNode* pre = preHead;
	while (h1 && h2)
	{
		if (h1->val < h2->val)
		{
			pre->next = new ListNode(h1->val);
			h1 = h1->next;
		}
		else
		{
			pre->next = new ListNode(h2->val);
			h2 = h2->next;
		}
		pre = pre->next;
	}
	pre->next = h1 == nullptr ? h2 : h1;
	return preHead->next;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	int num[] = { 1,8,3,6,5,4,7,2,9 };
	ListNode* h1 = constructList(num, 9);
	ListNode* even = new ListNode(0);
	ListNode* odd = new ListNode(0);
	ListNode* e = even;
	ListNode* o = odd;
	splitList(h1, e, o);
	ListNode* ecopy = e->next;
	while (ecopy)
	{
		cout << ecopy->val << " ";
		ecopy = ecopy->next;
	}
	cout << "e" << endl;
	ListNode * ocopy = o->next;
	while (ocopy)
	{
		cout << ocopy->val << " ";
		ocopy = ocopy->next;
	}
	cout << "o" << endl;

	ListNode* h2 = reverseList(o->next);
	ListNode* h3 = mergeList(e->next, h2);
	while (h3)
	{
		cout << h3->val << " ";
		h3 = h3->next;
	}
	return a.exec();
}
