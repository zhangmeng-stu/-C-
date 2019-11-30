#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.洗牌
/*这个洗牌其实就是把好比123456分成两份，123和456，然后先放把123放进
大小为6的vec中：变成1_2_3_，再把456反向放入，变成142536，这就是一次
洗牌的过程。*/

vector<int> shuffle(vector<int> v) {
	vector<int> ans(v.size());
	int k = 0;
	for (int i = 0; i < v.size() / 2; i++) {
		ans[k] = v[i];
		k += 2;
	}
	k = v.size() - 1;
	for (int i = v.size() - 1; i >= v.size() / 2; i--) {
		ans[k] = v[i];
		k -= 2;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> poke(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> poke[i];
		}
		while (k--) {
			poke = shuffle(poke);
		}
		cout << poke[0];
		for (int i = 1; i < poke.size(); i++) {
			cout << " " << poke[i];
		}
		cout << endl;
	}
}
#endif 

#if 0
//2.MP3光标位置
//将n首歌曲编号放入playlist中，因此playlist={1,2，...n};
//屏幕上呈现的歌曲编号由win_pos 和win_size共同确定。
//cursor则是光标指定的歌曲编号的下标
//核心就是根据输入的数字和字符串确定win_pos 和win_size以及cursor.


int main()
{
	int n;
	string ins;//instruction：指令
	while (cin >> n >> ins)
	{
		int cursor = 0;//光标定位
		int win_pos = 0;//窗定位
		int win_size = 4;
		vector<int> playlist(n, 0);
		for (int i = 0; i < n; i++)
		{//初始化播放列表
			playlist[i] = i + 1;
		}
		if (n <= 4)
		{
			win_size = n;
			for (int i = 0; i < ins.length(); i++)
			{
				if (ins[i] == 'U')
				{
					cursor == 0 ? cursor = n - 1 : cursor--;
				}
				else
				{
					cursor == n - 1 ? cursor = 0 : cursor++;
				}
			}
		}
		else
		{
			for (int i = 0; i < ins.length(); i++)
			{
				if (ins[i] == 'U')
				{
					if (cursor == 0)
					{
						cursor = n - 1;//光标移到最下
						win_pos = n - 4;//窗定位也要相应的移动
					}
					else{
						if (cursor == win_pos)
						{
							win_pos--;//光标移动
							cursor--;//窗定位相应的移动
						}
						else
						{
							cursor--;//只有光标移动
						}
					}
				}
				else
				{//ins[i]=='D'
					if (cursor == n - 1)
					{
						cursor = 0;//光标移到最上
						win_pos = 0;//窗定位也要相应的移动
					}
					else
					{
						if (cursor == win_pos + 3)
						{
							cursor++;//光标移动
							win_pos++;//窗定位相应的移动
						}
						else
						{
							cursor++;//只有光标移动
						}
					}
				}
			}
		}
		for (int i = win_pos; i < win_pos + win_size; i++)
		{
			cout << playlist[i] << " ";
		}
		cout << endl;
		cout << playlist[cursor] << endl;
	}
	system("pause");
	return 0;
}
#endif 

#if 0
//小易的升级之路
int GOD(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return (a);
}
int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (c >= temp)
				c += temp;
			else
				c += GOD(c, temp);
		}
		cout << c << endl;
	}
	return 0;
}
#endif

//找出字符串中第一个只出现一次的字符(题面已经更新)
int main()
{
	string str;
	while (getline(cin, str))
	{
		size_t i, j;
		for ( i = 0; i < str.size(); i++)
		{
			char ch = str[i];
			for ( j = 0; j < str.size(); j++)
			{
				if (ch == str[j] && i != j)
					break;
			}
			if (j == str.size())
				break;
		}
		if (i == str.size())
			cout << "-1" << endl;
		else
			cout << str[i] << endl;
	}
	return 0;
}