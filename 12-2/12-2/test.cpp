#include <iostream>
#include <vector>
using namespace std;

#if 0
/*1.С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�����
��Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У�
�������36����ֵ���ȵ����ÿ��С���������������һ�����
����Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��
һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����*/
class Bonus 
{
public:
	int getMost(vector<vector<int> > board) 
	{
		int dp[6][6];
		dp[0][0] = board[0][0];
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (!j && !i)
					continue;
				else
					dp[i][j] = max((j == 0) ? 0 : dp[i][j - 1], (i == 0) ? 0 : dp[i - 1][j]) + board[i][j];
			}
		}
		return dp[5][5];
	}
};

#endif

//�Թ�����
/*
MazeTrack()���������ݹ����Թ������岽��Ϊ��
1. ���Ƚ���ǰ�����·����������Ϊ����
2. �жϵ�ǰ���Ƿ�Ϊ���ڣ��������·��������������ת��4
3. �����жϵ�ǰ����ϡ��¡������ĸ����Ƿ���ߣ����������ݹ��߸õ�
4. ��ǰ���Ƴ�·��������Ϊ����*/
int N, M;
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·��
vector<vector<int>> path_best;//�洢���·��
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });
   if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
		//�ж��Ƿ񵽴��յ�
	{
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);
	maze[i][j] = 0;
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i:maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return  0;
}