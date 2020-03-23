#include <iostream>
using namespace std;
#include <vector>

/*ջ��ѹ�롢��������
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
˼·���Ƚ�Ԫ�ش���vector�У�Ȼ����pop�е�Ԫ�ؽ��бȽ�*/

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

/*�������´�ӡ������
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ*/
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