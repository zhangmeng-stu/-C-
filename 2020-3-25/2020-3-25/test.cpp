#include <iostream>
using namespace std;

/*链表中的倒数第K个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，
即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* slow = head;
		ListNode* fast = head;
		for (int i = 1; i<k; i++)
		{
			fast = fast->next;
		}

		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;

	}
};

/*复杂链表的复制
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/

struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* cur = pHead;
		while (cur != NULL)
		{
			RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
			node->label = cur->label;
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}
		cur = pHead;
		while (cur != NULL)
		{
			if (cur->random == NULL)
				cur->next->random = NULL;
			else
			{
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		cur = pHead;
		RandomListNode* newhead = pHead->next;
		while (cur != NULL)
		{
			RandomListNode* node = cur->next;
			cur->next = node->next;
			if (node->next != NULL)
				node->next = node->next->next;
			cur = cur->next;
		}
		return newhead;
	}
};