#include <iostream>
using namespace std;
#include <vector>

/*
����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]���Ҳ���A[K+1..N-1]��K����ȡֵ�ķ�Χ��[0,N-2]��
����ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�
˼·���������ֵ�����ֵ���ڵķ���һ����ĳһ�˿�ʼ���������е���ֵ�ȸöεĶ˴�
���С�ö����ֵ�����ֵ�Ĳ����ֻ��Ƚ����ֵ�����˵Ĳ���ĸ���
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
����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�

����int����mat,�Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������

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
			//��-����        
			for (int i = start; i <= endX; ++i)
				imat.push_back(mat[start][i]);
			//��-����         
			if (start<endY)
			{
				for (int i = start + 1; i <= endY; ++i)
					imat.push_back(mat[i][endX]);
			}
			//��-����    
			if (start<endX&&start<endY)
			{
				for (int i = endX - 1; i >= start; --i)
					imat.push_back(mat[endY][i]);
			}
			//��-����      
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

