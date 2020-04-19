#include <iostream>
using namespace std;
#include <vector>

/*
给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K+1..N-1]，K可以取值的范围是[0,N-2]。
求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？
思路：先求最大值，最大值不在的分区一定从某一端开始，若分区中的数值比该段的端大，
会减小该段最大值与最大值的差，所以只需比较最大值与两端的差别哪个大
*/
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		int max = A[0];
		for (int i = 1; i < n; i++)
		{
			if (A[i]>max)
				max = A[i];
		}
		return max - A[0] > max - A[n - 1] ? max - A[0] : max - A[n - 1];
	}
};

/*
对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。

给定int矩阵mat,以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。

*/

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m)
	{
		int start = 0;
		vector<int> imat;
		while (n>start * 2 && m>start * 2)
		{
			int endX = m - 1 - start;
			int endY = n - 1 - start;
			//左-》右        
			for (int i = start; i <= endX; ++i)
				imat.push_back(mat[start][i]);
			//上-》下         
			if (start<endY)
			{
				for (int i = start + 1; i <= endY; ++i)
					imat.push_back(mat[i][endX]);
			}
			//右-》左    
			if (start<endX&&start<endY)
			{
				for (int i = endX - 1; i >= start; --i)
					imat.push_back(mat[endY][i]);
			}
			//下-》上      
			if (start<endX&&start<endY - 1)
			{
				for (int i = endY - 1; i >= start + 1; --i)
					imat.push_back(mat[i][start]);
			}
			++start;
		}
		return imat;
	}

};

