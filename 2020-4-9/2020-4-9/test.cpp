#include <iostream>
using namespace std;


/*


NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。于是他就思考，
要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件
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
广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。 
例如队伍的身高数据是（1、7、3、5、9、4、8），其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
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