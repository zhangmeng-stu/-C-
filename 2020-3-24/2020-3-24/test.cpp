#include <iostream>
#include <vector>
using namespace std;

/*�����������ĺ������
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
*/
//�ǵݹ�
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

//�ݹ�˼·�����ҵ����ڵ㣬Ȼ�������������Էֱ����������������洢�������еݹ��ж�
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

/*�������к�Ϊĳһֱ��·��
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
˼·;����һ����ά�������洢·�������жϸ��ڵ��Ƿ����㣬Ȼ��ѭ��������������*/


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

/*ɾ������ĵ�����n���ڵ�*/

 
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