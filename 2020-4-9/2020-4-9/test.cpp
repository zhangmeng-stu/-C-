#include <iostream>
using namespace std;


/*


NowCoderÿ��Ҫ���ܶ��˷��ʼ�����һ�������ַ������ʼ����ѷ���A���ʼ�������B���ѷ���B���ʼ�������A����������˼����
Ҫ��n���˷��ʼ�����ÿ���˽��յ�1���ʼ�������£��ж���������������˶��յ��˴�����ʼ���
��û�����յ������Լ����ʼ�
*/

long int fail(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(fail(n - 1) + fail(n - 2));
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << fail(n) <<endl;
	}
	return 0;
}


/*
�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ������æ�ҳ�������ε����������С� 
����������������ǣ�1��7��3��5��9��4��8�����������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��
*/
#include <vector>

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> h(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		vector<int> f(n, 1);
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (h[i]>h[j])
				{
					f[i] = max(f[i], f[j]+1);
				}
			}
			count = max(count, f[i]);
		}
		cout << count << endl;
	}
}