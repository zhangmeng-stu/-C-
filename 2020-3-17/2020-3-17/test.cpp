#include <stack>

#include <iostream>
#include <vector>
using namespace std;

/*3.从尾到头打印链表
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
思路：1.递归*/
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL){

	}
};
class Solution {
public:
	vector<int> New;//放在外面，要不然递归会再次创建
	vector<int> printListFromTailToHead(ListNode* head) {

		ListNode *cur = head;
		if (cur != NULL)
		{
			if (cur->next != NULL)
			{
				printListFromTailToHead(cur->next);
			}
			New.push_back(cur->val);
		}
		return New;
	}
};
/*思路2：利用栈（先进后出的特性）*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> New;
		ListNode*cur = head;
		stack<int> sta;
		while (cur != NULL)
		{
			sta.push(cur->val);
			cur = cur->next;
		}
		while (!sta.empty())
		{
			New.push_back(sta.top());
			sta.pop();
		}
		return New;
	}
};

/*4.重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
思路：
*/


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int len = vin.size();
		if (len == 0)
			return NULL;
		vector<int> left_pre, right_pre, left_vin, right_vin;
		TreeNode* root = new TreeNode(pre[0]);//创建根节点
		int count = 0;
		for (int i = 0; i<len; i++)
		{
			if (vin[i] == pre[0])
			{
				count = i;
				break;
			}
		}
		for (int i = 0; i<count; i++)//左子树
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);//前序第一个为根节点
		}
		for (int i = count + 1; i<len; i++)//右子树

		{
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};