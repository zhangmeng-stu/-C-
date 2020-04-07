#include <iostream>
using namespace std;

/*�����
��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�
ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
*/
#include <vector>
void BlockCount(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
	if (x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
		return;
	count++;
	v[x][y] = '1';
	BlockCount(v, x - 1, y, m, n, count); 
	BlockCount(v, x, y - 1, m, n, count);
	BlockCount(v, x + 1, y, m, n, count);
	BlockCount(v, x, y + 1, m, n, count);

}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int x, y;
		int count = 0;
		vector<vector<char>> v(m, vector<char>(n, 0));
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		BlockCount(v, x, y, m, n, count);
		cout << count << endl;
	}
	return 0;
}


/*
��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1,1),B��(n,m)��
����A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),
�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
*/

#include <iomanip>
#include <cstring>

int has[25][25];
double dp[25][25];

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int i, j;
		memset(has, 0, sizeof(has));
		memset(dp, 0, sizeof(dp));
		int x, y;
		for (i = 0; i < k; i++)
		{
			cin >> x >> y;
			has[x][y] = 1;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1) { dp[1][1] = 1; continue; }
				if (has[i][j]) { dp[i][j] = 0; continue; }
				if (i == n && j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; continue; }
				if (i == n) { dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; continue; }
				if (j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; continue; }
				if (i == 1) { dp[i][j] = dp[i][j - 1] * 0.5; continue; }
				if (j == 1) { dp[i][j] = dp[i - 1][j] * 0.5; continue; }
				dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
			}
		}
		cout << fixed << setprecision(2) << dp[n][m] << endl;
	}
	return 0;
}