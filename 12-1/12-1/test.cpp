#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
//若没有金额超过总数的一半，返回0。
class Gift 
{
public:
	int getValue(vector<int> gifts, int n) 
	{
		if (gifts.size() < n)
			return 0;
		if (gifts.size() == 0)
			return 0;
		int count = 0, temp;
		for (int i = 0; i < n; i++)
		{
			if (count == 0)
			{
				temp = gifts[i];
				count = 1;
			}
			else
			{
				if (temp == gifts[i])
					count++;
				else
					count--;
			}
		}
		int size = 0;
		for (int i = 0; i < n; i++)
		{
			if (temp == gifts[i])
				size++;
		}
		return(size>n / 2) ? temp : 0;
	}
};
#endif

//计算字符串的距离
//给定任意两个字符串，写出一个算法计算它们的编辑距离。
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int n = a.size(), m = b.size();
		vector<vector<int>> dp(n + 1, vector <int>(m + 1));
			/*dp[x][y]代表将a字符串的前x个字符（从1编号，a的前1个字符为a[0],
			前两个字符为a[0]和a[1]）转换成b字符串的前y个字符 */
		for (int i = 0; i <= n; i++)
			dp[i][0] = i;
		for (int j = 0; j <= m; j++)
			dp[0][j] = j;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int d1 = dp[i - 1][j]+1, d2 = dp[i][j - 1] + 1, d3 = dp[i - 1][j - 1];
				if (a[i - 1] != b[j - 1])
					d3 += 1;
				dp[i][j] = min(min(d1, d2), d3);
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}