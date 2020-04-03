#include <iostream>
using namespace std;

/*年会抽奖
今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
思路：
假设a的名字没有被a拿到，其他n - 1个人都有可能拿到，即有n - 1种情况。假设b拿到了a的名字，那么对于b的名字有两种情况，
第一种是b的名字被a拿到了，也就是a、b互相拿到了对方的名字，那么对于其他n - 2个人互相拿错又是一个子问题f(n - 2).
第二种是b的名字没有被a拿到，则剩下的问题是子问题f(n - 1).
因此可得递推公式f(n) = (n - 1) * (f(n - 1) + f(n - 2)).

最终得出公式n人都不获奖的概率h(n) = (n - 1) * (f(n - 1) + f(n - 2)) / (n!)

*/
int main()
{
	int n = 0;
	//fTable[n]记录n个人都拿错（全不获奖）的情况种数，allTable[n]记录所有可能的组合情况n的阶乘
	long long ftable[21] = { 0, 0, 1 }, alltable[21] = { 0, 1, 2 };
	for (int i = 3; i < 21; i++)
	{
		ftable[i] = (i - 1)*(ftable[i - 1] + ftable[i - 2]);
		alltable[i] = i*alltable[i - 1];
	}
	while (cin >> n && n != -1)
	{
		////注意%属于控制字符，两个连续的%%才表示真正的%字符
		printf("%4.2lf%%\n", 100 * double(ftable[n]) / alltable[n]);

	}
	return  0;
}


/*抄送列表


输入有多组数据，每组数据有两行。

第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。

第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
思路：对发送的列表逐一判断，进行筛选*/

#include <string>

int main()
{
	string s, res;
	while (getline(cin, s))
	{
		getline(cin, res);
		bool sta = false;
		for (int i = 0; i < s.length(); i++)
		{
			string t;
			if (s[i] == '"')
			{
				i++;
				while (i < s.length() && s[i] != '"')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
			else if (s[i] != ',')
			{
				while (i < s.length() && s[i] != ',')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
		}
		if (sta == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}