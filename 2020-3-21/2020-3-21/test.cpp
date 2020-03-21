#include <iostream>
using namespace std;

/*��ת����
����һ��������ת��������������ı�ͷ��
˼·������һ���յ�������ͷ��β����ԭ�����ÿ����㣬�ѱ������Ľڵ㣬ͷ�嵽���������*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode *resultHead = NULL;
		ListNode *cur = pHead;
		while (cur != NULL)
		{
			ListNode *next = cur->next;
			cur->next = resultHead;
			resultHead = cur;
			cur = next;
		}
		return resultHead;
	}
};

/*�ϲ�������������
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
˼·���������������Ƚϴ�С��ѡ��С��β�嵽�����*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
		{
			return pHead2;
		}
		if (pHead2 == NULL)
		{
			return pHead1;
		}
		ListNode *rHead = NULL;
		ListNode *cur1 = pHead1;
		ListNode *cur2 = pHead2;
		ListNode *last = NULL;//���������һ���ڵ�
		while (cur1 != NULL && cur2 != NULL)
		{

			if (cur1->val <= cur2->val)
			{
				ListNode *next = cur1->next;
				cur1->next = NULL;//cur1����β�嵽����������cur1��һ��Ϊ��
				if (rHead == NULL)
				{
					rHead = cur1;
				}
				else
				{
					last->next = cur1;
				}
				last = cur1;
				cur1 = next;
			}
			else
			{
				ListNode *next = cur2->next;
				cur2->next = NULL;
				if (rHead == NULL)
				{
					rHead = cur2;
				}
				else
				{
					last->next = cur2;
				}
				last = cur2;
				cur2 = next;
			}
		}
		//һ������������
		if (cur1 != NULL)
		{
			last->next = cur1;
		}
		else
		{
			last->next = cur2;
		}
		return rHead;
	}
};

/*�����ӽṹ
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
˼·���Ӹ���ʼ����*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL)
		{
			if (pRoot1->val == pRoot2->val)
			{
				result = DoTree1HaveTree2(pRoot1, pRoot2);
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
	bool  DoTree1HaveTree2(TreeNode* node1, TreeNode* node2)
	{
		if (node2 == NULL)
		{
			return true;
		}
		if (node1 == NULL)
		{
			return false;
		}
		if (node1->val != node2->val)
		{
			return false;
		}
		return  DoTree1HaveTree2(node1->left, node2->left) && DoTree1HaveTree2(node1->right, node2->right);
	}
};