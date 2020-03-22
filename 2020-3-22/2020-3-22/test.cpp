#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*����������
���������Ķ�����������任ΪԴ�������ľ���*/


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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return ;
		if (pRoot->left == NULL && pRoot->right)
			return;
		swap(pRoot->left, pRoot->right);//ֱ�ӽ�����Ϊ����
		if (pRoot->left != NULL)
			Mirror(pRoot->left);
		if (pRoot->right != NULL)
		{
			Mirror(pRoot->right);
		}

	}
};

/*˳ʱ���ӡ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬
�����������4 X 4���� 1  2  3   4 
                        5  6  7   8 
						9  10 11  12 
						13 14 15  16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
˼·���ȴ�ӡ�������һȦ*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		res.clear();
		int row = matrix.size();//����
		int col = matrix[0].size();//����
		int circle = ((row < col ? row : col) - 1) / 2 + 1;//Ȧ��
		for (int i = 0; i < circle; i++)
		{
			for (int j = i; j < col - i; j++)//�������Ҵ�ӡ
			{
				res.push_back(matrix[i][j]);
			}
			for (int k = i + 1; k < row - i; k++)//�������´�ӡ
			{
				res.push_back(matrix[k][col - 1 - i]);
			}
			

				/**�����ظ���ӡ����������������л�������ʱ�����һȦֻ����һ�л���һ�У�
				*�������ӡ�������ٴ�ӡʱ�������ظ���ӡ��,���������ӡ������ѭ�����жϵ�ǰ��
				*�ǲ��ǵ��У�ʵ�ʾ��Ǹ����У���������ż����Ȧ���Ĺ�ϵ�����Ӷ������Ƿ��ӡ
				*/
			for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--)
				res.push_back(matrix[row - i - 1][m]);
			for (int n = row - i - 2; (n > i) && (col - i - 1 != i); n--)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};

/*����min������ջ
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
˼·����������һ�������洢���ݣ�һ�������洢��Сֵ*/

class Solution {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty())
			s2.push(value);
		else if (value <= s2.top())
		{
			s2.push(value);
		}
	}
	void pop() {
		if (s1.top() == s2.top())
			s2.pop();
		s1.pop();

	}
	int top() {
		return s1.top();
	}
	int min() {
		return s2.top();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

//���ֲ���
int binarySearch(int a[], int size, int value)
{
	int left = 0;
	int right = size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (value == a[mid])
		{
			return mid;
		}
		else if (value < a[mid])
			right = mid;
		else if (value>a[mid])
			left = mid + 1;
	}
	return -1;
}