#include <iostream>
#include <set>
using namespace std;

/*
上图是一个电话的九宫格，如你所见一个数字对应一些字母，
因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
例如公司的Help Desk号码是4357，
因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。
同理，TUT-GLOP就代表888-4567、310-GINO代表310-4466。
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
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来

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