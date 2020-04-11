#include <iostream>
using namespace std;
/*
解读密码
nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。
思路：取出数字即可
*/
#include <string>
int main()
{
	string str;
	while (getline(cin, str))
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
/*
走迷宫：#代表墙，.代表通路
*/

#include <queue>
#define N 10
char maze[N][N];
bool mark[N][N];

struct point
{
	int x, y;
	int step;
};
queue<point>Q;
int goTable[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};
int BFS(int a, int b)
{
	while (Q.empty() == false)
	{
		point p = Q.front();
		Q.pop();
		int x = p.x;
		int y = p.y;
		for (int i = 0; i < 4; i++)
		{
			int gx = x + goTable[i][0];
			int gy = y + goTable[i][1];
			if (gx < 0 || gx >= a || gy < 0 || gy >= b)
				continue;
			if (mark[gx][gy] == true)
				continue;
			if (maze[gx][gy] == '#')
				continue;
			point newP;
			newP.x = gx;
			newP.y = gy;
			newP.step = p.step + 1;
			mark[gx][gy] = true;
			Q.push(newP);
			if (gx == a - 1 && gy == b - 2)
				return newP.step;
		}

	}
}

int main()
{
	while (cin >> maze[0][0])
	{
		mark[0][0] = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == 0 && j == 0)
					continue;
				cin >> maze[i][j];
				mark[i][j] = false;
			}
		}
		point temp;
		temp.x = 0;
		temp.y = 1;
		temp.step = 0;
		mark[0][1] = true;
		while (!Q.empty())
			Q.pop();
		Q.push(temp);
		int ret = BFS(N, N);
		cout << ret << endl;
	}
	return 0;
}