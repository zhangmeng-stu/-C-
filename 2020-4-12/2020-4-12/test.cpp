#include <iostream>
#include <set>
using namespace std;

/*
��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ��
����ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ��
���繫˾��Help Desk������4357��
��Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��
ͬ��TUT-GLOP�ʹ���888-4567��310-GINO����310-4466��
*/
//int main()
//{
//	string s;
//	int length;
//	string NUM = "22233344455566677778889999";
//	while (cin >> length)
//	{
//		set<string> data;
//		int cnt;
//		for (int i = 0; i < length; i++)
//		{
//			cnt = 0;
//			string res;
//			cin >> s;
//			for (int j = 0; j < s.length(); j++)
//			{
//				if (s[j] >= 'A'&&s[j] <= 'Z')
//				{
//					res += NUM[s[j] - 'A'];
//					cnt++;
//					if (cnt == 3)
//						res += "-";
//				}
//				else if (s[j] >= '0'&&s[j] <= '9')
//				{
//					res += s[j];
//					cnt++;
//					if (cnt == 3)
//						res += "-";
//				}
//			}
//			data.insert(res);
//		}
//		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
//			cout << *it << endl;
//		cout << endl;
//	}
//	return 0;
//}


/*
������������ n �� m��������1��2��3.......n ������ȡ������,ʹ��͵��� m ,Ҫ���������еĿ�������г���

*/
#include <vector>

void help(int n, int m, vector<int>& v, int beg)
{
	if (m == 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++)
	{
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		help(n, m, v, 1);
	}
	return 0;
}