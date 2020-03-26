#include <iostream>
using namespace std;
#include <vector>
/*������������˫������
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
˼·�����������������������ָ��ı�*/


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
	void inorder(TreeNode *node) {
		if (node == NULL) {
			return;
		}

		inorder(node->left);
		toDList(node);
		inorder(node->right);
	}
	TreeNode* head = NULL;
	TreeNode* prev = NULL;
	void toDList(TreeNode* node)
	{
		node->left = prev;
		if (prev != NULL)
		{
			prev->right = node;
		}
		else
		{

			head = node;
		}
		prev = node;
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		head = NULL; prev = NULL;
		inorder(pRootOfTree);

		return head;
	}

};

/*�ַ�������
����һ���ַ���,���ֵ����ӡ�����ַ������ַ�����������*/



class Solution {
public:
	vector<string> Permutation(string str)
	{
		vector<string> result;
		if (str.empty()) return result;

		Permutation(str, result, 0);

		// ��ʱ�õ���result�����в������ֵ�˳�򣬿��Ե�����������
		sort(result.begin(), result.end());

		return result;
	}

	void Permutation(string str, vector<string> &result, int begin)
	{
		if (begin == str.size() - 1) // �ݹ���������������Ѿ�ָ��str���һ��Ԫ��ʱ
		{
			if (find(result.begin(), result.end(), str) == result.end())
			{
				// ���result�в�����str������ӣ�����aa��aa�ظ���ӵ����
				result.push_back(str);
			}
		}
		else
		{
			// ��һ��ѭ��i��begin��ȣ��൱�ڵ�һ��λ�����������ؼ�����֮���ѭ����
			// ֮��i != begin����ύ��������ͬλ���ϵ��ַ���ֱ��begin==str.size()-1�����������
			for (int i = begin; i<str.size(); ++i)
			{
				swap(str[i], str[begin]);
				Permutation(str, result, begin + 1);
				swap(str[i], str[begin]); // ��λ�����Իָ�֮ǰ�ַ���˳�򣬴ﵽ��һλ���θ�����λ������Ŀ��
			}
		}
	}

	void swap(char &fir, char &sec)
	{
		char temp = fir;
		fir = sec;
		sec = temp;
	}
};