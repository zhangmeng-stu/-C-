#include <iostream>
using namespace std;
#include <vector>

/*栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
思路：先将元素存入vector中，然后与pop中的元素进行比较*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0)
			return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size();)
		{
			stack.push_back(pushV[i++]);
			while (j < popV.size() && stack.back() == popV[j])
			{
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};

/*从上往下打印二叉树
从上往下打印出二叉树的每个节点，同层节点从左至右打印*/
#include <queue>
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> vec;
		if (root == NULL)
			return vec;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vec.push_back(q.front()->val);
			if (q.front()->left != NULL)
				q.push(q.front()->left);
			if (q.front()->right != NULL)
				q.push(q.front()->right);
			q.pop();
		}
		return vec;
	}
};