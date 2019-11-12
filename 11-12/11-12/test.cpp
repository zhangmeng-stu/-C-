#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*1.Fibonacci����
Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N��
���������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����*/
#if 0
int main()
{
	int N, r, l, f0 = 0, f1 = 1, f;
	cin >> N;
	if (N == 1)
		cout << 0 << endl;
	else
	{
		while (1)
		{
			f = f0 + f1;
			f0 = f1;
			f1 = f;
			if (f < N)
				l = N - f;
			else
			{
				r = f - N;
				break;
			}
		}
		cout << min(l, r) << endl;
	}
	return 0;
}

#endif

//�Ϸ����������ж�
/*����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n��
�뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���*/

class Parenthesis
{
public:
	bool chkParentesis(string A, int n)
	{
		if (n % 2 == 1)
			return false;
		stack<char> s1;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '(')
				s1.push(A[i]);
			else if (A[i] == ')')
			{
				if (s1.empty())
					return false;
				s1.top();
			}
			else
				return false;
		}
		if (s1.empty())
			return true;
	}
};