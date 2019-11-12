#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*1.Fibonacci数列
Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，
你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。*/
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

//合法括号序列判断
/*对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，
请返回一个bool值代表它是否为一个合法的括号串。*/

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