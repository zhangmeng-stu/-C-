#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*二叉树镜像
操作给定的二叉树，将其变换为源二叉树的镜像。*/


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
		swap(pRoot->left, pRoot->right);//直接交换成为镜像
		if (pRoot->left != NULL)
			Mirror(pRoot->left);
		if (pRoot->right != NULL)
		{
			Mirror(pRoot->right);
		}

	}
};

/*顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1  2  3   4 
                        5  6  7   8 
						9  10 11  12 
						13 14 15  16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
思路：先打印最外面的一圈*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		res.clear();
		int row = matrix.size();//行数
		int col = matrix[0].size();//列数
		int circle = ((row < col ? row : col) - 1) / 2 + 1;//圈数
		for (int i = 0; i < circle; i++)
		{
			for (int j = i; j < col - i; j++)//从左向右打印
			{
				res.push_back(matrix[i][j]);
			}
			for (int k = i + 1; k < row - i; k++)//从上向下打印
			{
				res.push_back(matrix[k][col - 1 - i]);
			}
			

				/**避免重复打印，即如果出现奇数行或奇数列时，最后一圈只会有一列或者一行，
				*当正向打印后，逆向再打印时，就是重复打印了,故在逆向打印的两个循环里判断当前行
				*是不是单行（实际就是根据行，列数的奇偶性与圈数的关系），从而决定是否打印
				*/
			for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--)
				res.push_back(matrix[row - i - 1][m]);
			for (int n = row - i - 2; (n > i) && (col - i - 1 != i); n--)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};

/*包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
思路：定义两个一个用来存储数据，一个用来存储最小值*/

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

//二分查找
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