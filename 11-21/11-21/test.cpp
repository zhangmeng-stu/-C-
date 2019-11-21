#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
//1.幸运袋子数
/*一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
思路：
 1 个 1 时——首先看 1 2，符合题意，扩展一位 1 2 2，符合题意，扩展一位 1 2 2 2，不符，
 回溯至上一位，1 2 2，最后一位变数，1 2 3，不符合题意，回溯至上一位， 1 2，最后一位
 换数，1 3，符合题意，由于无法扩展，最后一位换数，1 4，符合题意，再次换数。数无，
 结束。此时个数为 4；
 2 个 1 时——首先看 1 1 2 符合题意，扩展一位 1 1 2 2 符合题意，1 1 2 2 2 不符合，回溯
 至上一位并换数 1 1 2 3，符合，继续换数 1 1 2 4不符合，回溯，1 1 3……
 得到结果 16。你们会发现少了 2 个。这是因为此方法没有计算全是 1 的情况。当数组中只
 有 1 时，1 的个数 - 1即使最优解*/
int cont = 0;
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
{
	for (int i = nowBit; i < list.size(); i++)
	{
		sum += list[i];
		mult *= list[i];
		if (sum <= mult)
			break;
		else
			cont++;
		ContOne(OneNub, list, i + 1, sum, mult);
		sum -= list[i];
		mult /= list[i];
		while (i < list.size() - 1 && list[i] == list[i + 1])
			i++;
	}
}
int main()
{
	int n, numb, OneCont(0);//OneCont用来记录1的总个数
	vector<int> list;
	cin >> n;
	while (n--)
	{
		cin >> numb;
		if (numb > 1)
			list.push_back(numb);
		else
			OneCont++;
	}
	cont = OneCont - 1; //将纯1数组先计算出来
	if (!list.empty())
	{
		sort(list.begin(), list.end());
		for (int i = 1; i <= OneCont; i++)
			ContOne(i, list, 0, i,1);
	}
	cout << cont << endl;
	return 0;
}

#endif


//2.计算日期到天数的转换

int dataToday(int year, int month, int day)
{
	if (year <= 0 || month <= 0 || day <= 0 || month > 12 || day > 31)
		return - 1;
	int lemp[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int Nolemp[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool flag;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0))
		flag = true;
	else
		flag = false;
	if (flag)
	{
		if (day > lemp[month - 1])
			return -1;
	}
	else
	{
		if (day > Nolemp[month - 1])
			return -1;
	}
	int temp = 0;
	for (int i = 0; i < month - 1; i++)
	{
		if (flag)
			temp = temp + lemp[i];
		else
			temp = temp + Nolemp[i];
	}
	return temp + day;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << dataToday(year, month, day) << endl;
	}
	return 0;
}



#if 0
int dataToDay(int year, int month, int day)
{
	if (year <= 0 || month <= 0 || month>12 || day>31 || day <= 0) return -1;
	int lemp[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int Nolemp[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool flag;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		flag = true;
	else
		flag = false;
	if (flag)
	{
		if (day>lemp[month - 1]) return -1;
	}
	else
	{
		if (day>Nolemp[month - 1]) return -1;
	}
	int temp = 0;
	for (int i = 0; i<month - 1; i++)
	{
		if (flag)
			temp = temp + lemp[i];
		else
			temp = temp + Nolemp[i];
	}
	return temp + day;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << dataToDay(year, month, day) << endl;
	}

}
#endif