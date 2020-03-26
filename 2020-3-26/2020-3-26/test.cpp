#include <iostream>
using namespace std;
#include <vector>
/*二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
思路：先利用中序遍历，将结点的指向改变*/


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

/*字符串排序
输入一个字符串,按字典序打印出该字符串中字符的所有排列*/



class Solution {
public:
	vector<string> Permutation(string str)
	{
		vector<string> result;
		if (str.empty()) return result;

		Permutation(str, result, 0);

		// 此时得到的result中排列并不是字典顺序，可以单独再排下序
		sort(result.begin(), result.end());

		return result;
	}

	void Permutation(string str, vector<string> &result, int begin)
	{
		if (begin == str.size() - 1) // 递归结束条件：索引已经指向str最后一个元素时
		{
			if (find(result.begin(), result.end(), str) == result.end())
			{
				// 如果result中不存在str，才添加；避免aa和aa重复添加的情况
				result.push_back(str);
			}
		}
		else
		{
			// 第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
			// 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
			for (int i = begin; i<str.size(); ++i)
			{
				swap(str[i], str[begin]);
				Permutation(str, result, begin + 1);
				swap(str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
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