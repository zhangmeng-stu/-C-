#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.井字棋
class Board
{
public:
	bool checkWon(vector<vector<int>>board)
	{
		int len = board.size();
		//检查行
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; i++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//检查列
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//检查对角线
		int temp = 0;
		for (int i = 0; i < len; i++)
		{
			temp += board[i][i];
		}
		if (temp == len)
			return true;
		//检查副对角线
		temp = 0;
		for (int i = 0; i < len; i++)
		{
			temp += board[i][len - i - 1];
		}
		if (temp == len)
			return true;
		return false;

	}
};
#endif

//2.密码强度等级
int isAlpha(char c)
{
	if (c >= 'a'&&c <= 'z')
		return 1;
	if (c >= 'A'&& c <= 'Z')
		return 2;
	else
		return 0;
}
bool isdigital(char c)
{
	if (c >= '0'&&c <= '9')
		return true;
	return false;
}
void securityLevel(string s)
{
	int a[3] = { 0, 10, 20 };//字母加分项
	int b[3] = { 0, 10, 20 };//数字加分项
	int c[3] = { 0, 10, 25 };//字符加分项
	int d[3] = { 5, 10, 25 };//长度分
	int e[3] = { 2, 3, 5 };//奖励分
	int ia = 0, ib = 0, ic = 0, id = 0, ie = 0;
	int len = s.length();
	vector<int>scores = { 0, 25, 50, 60, 70, 80, 90 };
	vector<string> evaluate = { "VERY_WEAK", "WEAK", "AVERAGE", "STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE"  };
	int alpha = 0;//alpha=0没有字母，alpha=1只有大写或者小写字母，alpha=2大小写混合字母
	int alpha_lower = 0;//小写字母
	int alpha_upper = 0;//大写字母
	int num = 0;
	int character = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isAlpha(s[i]))
		{
			isAlpha(s[i]) == 1 ? alpha_lower = 1 : alpha_upper = 1;
		}
		else if (isdigital(s[i]))
		{
			num++;
		}
		else
		{
			character++;
		}
	}
	ia = alpha_lower + alpha_upper;
	ib = num == 0 ? 0 : (num == 1 ? 1 : 2);
	ic = character == 0 ? 0 : (character == 1 ? 1 : 2);
	id = len <= 4 ? 0 : (len <= 7 ? 1 : 2);
	if (ia == 1 && num > 0 && character == 0)
		ie = 0;
	else if (ia == 1 && num > 0 && character > 0)
		ie = 1;
	else if (ia == 2 && num > 0 && character > 0)
		ie = 2;
	int score = a[ia] + b[ib] + c[ic] + d[id] + e[ie];
	int i = 1;
	for (; i < scores.size(); i++)
	{
		if (score < scores[i])
		{
			break;
		}
	}
	cout << evaluate[i - 1] << endl;
}
int main()
{
	string s;
	while (cin >> s)
	{
		securityLevel(s);
	}
	return 0;
}