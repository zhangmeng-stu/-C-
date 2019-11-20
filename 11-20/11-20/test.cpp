#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

#if 0
/*С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK��ʯ�壬
С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����
������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� 
С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��
С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
˼·��
���ö�̬�滮˼����⡣����һ��vector����steps��
steps[i]��ʾ����i��ʯ���������С������
��ʼ��Ϊsteps����ΪINT_MAX��
�����N��ʯ�忪ʼ���������
��steps[i]ΪINT_MAX����ʾ�õ㲻�ɵ��ֱ�ӿ�ʼ�´�ѭ����
��steps[i]��ΪINT_MAX����ʾ�õ���Ե��
���������i��Լ�������ж�̬�滮����̬�滮��ת�Ʒ���Ϊ
steps[i+j] = min(steps[i]+1,steps[i+j])   //iΪʯ���ţ�jΪi��Լ��
steps[N] = 0*/

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++)
		{
			if (steps[i] == INT_MAX)
				continue;
			for (int j = 2; (j*j) <= i; j++)
			{
				if (i%j == 0)
				{
					if (i + j <= M)
					{
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M)
					{
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}
				}
			}
		}
		if (steps[M] == INT_MAX)
		{
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}
	return 0;
}

#endif

#if 0
//2.��������
/*
�������������������
xcopy /s c:\ d:\��
�����������£� 
����1��������xcopy 
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\
���дһ��������������ʵ�ֽ������и�����������������*/
int main()
{
	string str;
	while (getline(cin, str))
	{
		bool flag = false;
		vector<string> vec;
		string row;
		for (int i = 0; i < str.size(); i++)
		{
			if (flag)
			{
				if (str[i] != '\"')
					row += str[i];
				else
					flag = false;

			}
			else
			{
				if (str[i] == ' ')
				{
					vec.push_back(row);
					row = "";
				}
				else if (str[i] == '\"')
					flag = true;
				else
					row += str[i];
			}
		}
		vec.push_back(row);
		cout << vec.size() << endl;
		for (auto i : vec)
			cout << i << endl;
	}
	return 0;
}

#endif

int main()
{
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d", i, a, b, c);
}