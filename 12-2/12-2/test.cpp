#include <iostream>
#include <vector>
using namespace std;

#if 0
/*1.小东所在公司要发年终奖，而小东恰好获得了最高福利，
他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，
上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，
他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，
一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。*/
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

//迷宫问题
/*
MazeTrack()函数用来递归走迷宫，具体步骤为：
1. 首先将当前点加入路径，并设置为已走
2. 判断当前点是否为出口，是则输出路径，保存结果；跳转到4
3. 依次判断当前点的上、下、左、右四个点是否可走，如果可走则递归走该点
4. 当前点推出路径，设置为可走*/
int N, M;
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径
vector<vector<int>> path_best;//存储最佳路径
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });
   if (i == N - 1 && j == M - 1) //判断是否到达终点
		//判断是否到达终点
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