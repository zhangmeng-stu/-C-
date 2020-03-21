#include <iostream>
using namespace std;

/*反转链表
输入一个链表，反转链表后，输出新链表的表头。
思路：建立一个空的链表，从头到尾遍历原链表的每个结点，把遍历到的节点，头插到结果链表中*/


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

/*合并两个排序链表
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
思路：遍历两个链表，比较大小，选择小的尾插到结果上*/


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
		ListNode *last = NULL;//新链表最后一个节点
		while (cur1 != NULL && cur2 != NULL)
		{

			if (cur1->val <= cur2->val)
			{
				ListNode *next = cur1->next;
				cur1->next = NULL;//cur1即将尾插到新链表，所以cur1下一个为空
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
		//一个链表被处理完
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

/*树的子结构
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
思路：从根开始查找*/

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