#include <stack>

#include <iostream>
#include <vector>
using namespace std;

/*3.��β��ͷ��ӡ����
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
˼·��1.�ݹ�*/
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
	vector<int> New;//�������棬Ҫ��Ȼ�ݹ���ٴδ���
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
/*˼·2������ջ���Ƚ���������ԣ�*/
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

/*4.�ؽ�������
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
˼·��
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
		TreeNode* root = new TreeNode(pre[0]);//�������ڵ�
		int count = 0;
		for (int i = 0; i<len; i++)
		{
			if (vin[i] == pre[0])
			{
				count = i;
				break;
			}
		}
		for (int i = 0; i<count; i++)//������
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);//ǰ���һ��Ϊ���ڵ�
		}
		for (int i = count + 1; i<len; i++)//������

		{
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};