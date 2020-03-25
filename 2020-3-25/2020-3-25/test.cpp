#include <iostream>
using namespace std;

/*�����еĵ�����K���ڵ�
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ������
�������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

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

/*��������ĸ���
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�*/

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