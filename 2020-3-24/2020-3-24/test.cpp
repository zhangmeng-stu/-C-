#include <iostream>
#include <vector>
using namespace std;

/*二叉搜索树的后序遍历
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
//非递归
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (size == 0)
			return false;
		int i = 0;
		while (size--)
		{
			while (sequence[i++] < sequence[size]);
			while(sequence[i++] > sequence[size]);
			if (i < size)
				return false;
			i = 0;
		}
		return true;
	}
};

//递归思路：先找到根节点，然后后序遍历的特性分别将左子树和右子树存储，最后进行递归判断
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		int root = sequence[sequence.size() - 1];
		vector<int> leftSequence;
		int i = 0;
		for (i = 0; i < sequence.size() - 1; i++)
		{
			if (sequence[i] < root)
				leftSequence.push_back(sequence[i]);
			else
				break;
		}
		vector<int>rightSequence;
		for (int j = i; j < sequence.size() - 1; j++)
		{
			if (sequence[j]>root)
				rightSequence.push_back(sequence[j]);
			else
				return false;
		}
		bool left = true;
		if (!leftSequence.empty())
		{
			left = VerifySquenceOfBST(leftSequence);
		}
		bool right = true;
		if (!rightSequence.empty())
		{
			right = VerifySquenceOfBST(rightSequence);
		}
		return(left&&right);
	}
};

/*二叉树中和为某一直的路径
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
思路;定义一个二维数组来存储路径，先判断根节点是否满足，然后循环遍历左右子树*/


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
	vector<vector<int>> res;
	vector<int> path;
	void find(TreeNode* root, int sum)
	{
		if (root == NULL)
			return;
		path.push_back(root->val);
		if (!root->left&&!root->right&&sum == root->val)
			res.push_back(path);
		else
		{
			if (root->left)
				find(root->left, sum - root->val);
			if (root->right)
				find(root->right, sum - root->val);

		}
		path.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		find(root, expectNumber);
		return res;
	}
};

/*删除链表的倒数第n个节点*/

 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL | head->next == NULL)
			return NULL;
		ListNode *fast = head;
		ListNode *slow = head;
		for (int i = 0; i<n; i++)
		{
			fast = fast->next;
		}
		if (!fast)
		{
			return head->next;
		}
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};