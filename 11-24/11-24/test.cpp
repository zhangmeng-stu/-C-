#include <iostream>
#include <vector>
#include <string>

using namespace std;

#if 0
//1.查找输入整数二进制中1的个数

int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumberOf1(n) << endl;
	}
	return 0;
}
#endif

/*2.在地下室里放着n种颜色的手套，手套分左右手，
但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，
所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，
只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。
现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,
分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，
且一定存在至少一种合法方案。

//思路:
1. 先把手套为0（匹配肯定不成功的）的这种最坏情况全部拿出来
2. 找出两个数组中最小和（不包括0手套的）数组，把该数组中最大的手套依次
   全拿了，剩下最小的，拿一个
3. 再从多的数组中，拿出随便一个，就可以匹配*/

#if 0
class Gloves 
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) 
	{
			int min = 0, lmin = 0, rmin = 0;
		int lm = 26, rm = 26;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				min += left[i];
				min += right[i];
			}
			else
			{
				lmin += left[i];
				rmin += right[i];
				if (left[i] < lm)
					lm = left[i];
				if (right[i] < rm)
					rm = right[i];
			}
		}
		min += lmin > rmin ? (rmin - rm) : (lmin - lm);
		return min + 2;
	}
};

#endif

#if 0
/*
3.完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。*/

int BeatyCount(int num)
{
	int count = 0;
	for (int j = 3; j <= num; j++)
	{
		int sum = 0;
		for (int i = 1; i <= j / 2 + 1; i++)
		{
			if (j%i == 0)
			{
				sum += i;
			}
		}
		if (sum == j)
			count++;
	}
	return count;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << BeatyCount(num) << endl;
	}
	return 0;
}
#endif

//4.扑克牌大小
/*扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。*/


// 根据给定符号分割字符串
vector<string> split(const string &ip, char ch)
{
	vector<string> result;
	int start = 0;
	for (int i = 0; i < ip.size(); ++i)
	{
		if (ip[i] == ch)
		{
			result.push_back(string(ip.begin() + start, ip.begin() + i));
			start = i + 1;
		}
	}
	if (start < ip.size())
	{
		result.push_back(string(ip.begin() + start, ip.end()));
	}
	return result;
}

// 判断手牌中是否有joker
int has_joker(vector<string> &hand)
{
	int ret = 0;
	for (int i = 0; i < hand.size(); ++i)
	{
		if (hand[i] == "joker")
			ret |= 0x01;
		else if (hand[i] == "JOKER")
			ret |= 0x10;
	}
	return ret;
}

// 把手牌转换成相应的数值用来比较大小
// 也可以写成一张表，直接查表获取更快
int hand2int(string &left)
{
	if (left.size() == 2) // 10
		return 10;
	else if (isdigit(left[0])) // 3-9
		return left[0] - '0';
	else if (left[0] == 'J')
		return 11;
	else if (left[0] == 'Q')
		return 12;
	else if (left[0] == 'K')
		return 13;
	else if (left[0] == 'A')
		return 14;
	return -1;
}

int main(void)
{
	string line;
	while (getline(cin, line))
	{
		vector<string> hands = split(line, '-');
		vector<string> left_hand = split(hands[0], ' ');
		vector<string> right_hand = split(hands[1], ' ');

		int who_is_big = 0; // 0不能比较，1左大，-1右大
		// 先把joker挑出来
		int left_joker = has_joker(left_hand);
		int right_joker = has_joker(right_hand);

		if (left_joker != right_joker) // 出现了joker的情况,直接判断joker就好了
			who_is_big = (left_joker > right_joker ? 1 : -1);
		else if (left_hand.size() == right_hand.size()) // 手牌数一样的情况
			who_is_big = (hand2int(left_hand[0]) > hand2int(right_hand[0]) ? 1 : -1);
		else // 手牌数不一样的情况
		{
			// joker不用考虑了，只有炸弹了
			if (left_hand.size() == 4)
				who_is_big = 1;
			else if (right_hand.size() == 4)
				who_is_big = -1;
		}
		if (who_is_big == 1)
			cout << hands[0] << endl;
		else if (who_is_big == -1)
			cout << hands[1] << endl;
		else
			cout << "ERROR" << endl;

		cin.ignore();
	}
	return 0;
}