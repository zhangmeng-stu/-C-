#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
//1.统计每个月兔子的总数（菲波那切数列）递归实现即可
int Get(int month)
{
	if (month<3)
		return 1;
	else
		return Get(month - 1) + Get(month - 2);
}
int main()
{
	int month;
	while (cin >> month)
	{
		cout << Get(month) << endl;
	}
	return 0;
}

#endif

#if 0
//2.字符串通配符
/*实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符*/

int match_string(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>> a(len2+1, vector<int>(len1 + 1, 0));
	a[0][0] = 1;
	for (int i = 1; i <= len2; i++)
	{
		char ch = str2[i - 1];
		a[i][0] = a[i - 1][0] && (ch == '*');
		for (int j = 1; j <= len1; j++)
		{
			char ch2 = str1[i - 1];
			if (ch == '*')
				a[i][j] = a[i - 1][j] || a[i][j - 1];
			else
				a[i][j] = a[i - 1][j - 1] && (ch == '?' || ch2 == ch);
		}
	}
	return a[len1][len2];
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int rst = match_string(str1, str2);
		if (rst == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
#endif

 
int match_string(string m_str, string w_str) //match wildcard 通配符
{
	int m_len = m_str.size();
	int w_len = w_str.size();
	vector<vector<int> > b_dp(w_len + 1, vector<int>(m_len + 1, 0));
	//多加一行一列作为初始初值所用
	b_dp[0][0] = 1;
	for (int i = 1; i <= w_len; i++)
	{
		char ch = w_str[i - 1];
		////设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
		b_dp[i][0] = b_dp[i - 1][0] && (ch == '*');
		for (int j = 1; j <= m_len; j++)
		{
			char ch2 = m_str[j - 1];
			if (ch == '*')
				b_dp[i][j] = b_dp[i - 1][j] || b_dp[i][j - 1]; //当匹配字符为*号时，状态取决于上面状态和左边状态的值
			else
				b_dp[i][j] = b_dp[i - 1][j - 1] && (ch == '?' || ch2 == ch);
		}
	}
	return b_dp[w_len][m_len];

}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int rst = match_string(str2, str1);
		if (rst == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

}