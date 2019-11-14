#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.�������򷽷����ַ�����
vector<string> vec;

//�����ֵ�������
bool lexicographically()
{
	int i = 0;
	while ((i + 1) < vec.size())
	{
		if (vec[i].compare(vec[i + 1])>0)
			return 0;
		i++;
	}
	return 1;
}

//�����ַ�����С����
bool Lengths()
{
	int i = 0;
	while ((i + 1) < vec.size())
	{
		if (vec[i + 1].size() < vec[i].size())
			return 0;
		i++;
	}
	return 1;
}
int main()
{
	string str;
	int n,i = 0;
	bool b1, b2;
	cin >> n;
	while (i < n)
	{
		cin >> str;
		vec.push_back(str);
		i++;
	}
	b1 = lexicographically();
	b2 = Lengths();

	if (b1 && b2)
		cout << "both";
	else if (b1 && !b2)
		cout << "lexicographically";
	else if (!b1 && b2)
		cout << "Lengths";
	else
		cout << "none";

	return 0;
}

#endif

#if 0
/*2.������A��������B����С��������ָ�ܱ�A��B��������С��������ֵ��
���һ���㷨��������A��B����С������
*/

int main()
{
	int a, b,i;
	cin >> a >> b;
	for (i = a;; i++)
	{
		if (i%a == 0 && i%b == 0)
			break;
	}
	cout << i;
}

#endif

#if 0
//3.����ӷ�����ʹ��+��
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if (A == 0)
			return B;
		else if (B == 0)
			return A;
		else
			return addAB(A^B, (A&B) << 1);
	}
};

#endif 


#if 0
//����
int fun(int a)
{
	int c = 1 << 5;
	a =a^ (1 << 5) - 1;
	return a;
}
int main()
{
	int n = fun(21);
	cout << n;
	return 0;
}

#endif

/*4.���дһ�����������������Ӻ�������
����n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���
Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�*/
/*˼·
�õݹ������������½ǿ���ԭ��(0, 0)�����Ͻǿ�������(m, n)��
��(m, n)��>(0, 0)�ͷ������ߣ�
������һ����f(m, n - 1)��>(0, 0) ��������һ����f(m - 1, n)��>(0, 0)
ע�⣺�����Ǵ������߽磬Ҳ����˵f(x, 0)����f(0,x)��ֻ��һ��ֱ·�����ˣ������x�Ǳ�������
f(m, n) = f(m, n - 1) + f(m - 1, n)*/

int func(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 1;
	}
	return func(m, n - 1) + func(m - 1, n);
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << func(m, n) << endl;
	}
	return 0;
}