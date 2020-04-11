#include <iostream>
using namespace std;
/*
�������
nowcoderҪ�����ѽ���һЩ���е���Ϣ���������ĵ绰����ȡ������Ҫ����Щ������Ϣ���л����������������м����һЩ����ķ��ţ�������������һ�����롣
���������æ����һ����򣬽�����nowcoder�Ƕ����յ�����Ϣ����ȡ���м����õ���Ϣ��
˼·��ȡ�����ּ���
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
���Թ���#����ǽ��.����ͨ·
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