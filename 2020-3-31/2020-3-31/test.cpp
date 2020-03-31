#include <iostream>
using namespace std;

/*淘宝网店
NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。
*/

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int mons[13] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2 };
bool leepyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
int one(int year1, int month1, int &day1, int month2, int money, int flag)
{//提升日期到同月
	days[2] = leepyear(year1) ? 29 : 28;
	if (month1<month2)//提升到下一个月1号
	{
		money += (days[month1] - day1 + 1)*mons[month1++];
		day1 = 1;
	}
	while (month1<month2)//整月提升
		money += days[month1] * mons[month1++];
	if (flag)//跨年到下一年1月1日
		money += days[12] * mons[12];
	return money;
}
int main()
{
	int year1, month1, day1, year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int money = 0;
		if (year1<year2)//改同年
		{
			money = one(year1++, month1, day1, 12, money, 1);
			month1 = 1;
			while (year1<year2)//整年提升
				money += leepyear(year1++) ? 580 : 579;
		}
		money = one(year1, month1, day1, month2, money, 0) + (day2 - day1 + 1)*mons[month1];
		cout << money << endl;
	}
	return 0;
}

/*

NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。
当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
*/

int main()
{
	int fTable[100001] = { 0, 1, 2 };
	for (int i = 3; i < 100001; i++)
	{
		fTable[i] = fTable[i - 1] + fTable[i - 2];
		fTable[i] = fTable[i] % 100000;
	}
	int number = 0;
	while (scanf("%d", &number) != -1)
	{
		printf((number < 29 ? "%d\n" : "%06d\n"), fTable[number]);
	}
	return 0;
}



#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	//建立一张表，用于记录斐波拉契尔数列的各项值
	int fTable[100001] = { 0, 1, 2 };
	for (int i = 3; i < 100001; ++i) {
		fTable[i] = fTable[i - 1] + fTable[i - 2];
		//需要对每项进行求余，否则会溢出
		fTable[i] = fTable[i] % 1000000;
	}
	int number = 0;
	//scanf返回值为正确输出数据的变量个数，当一个变量都没有成功获取数据时，此时返回-1
	while (scanf("%d", &number) != -1) {
		//题目有些坑，number >= 29时前面补0,要用06d（输出结果不足六位需要补0）
		printf((number < 29 ? "%d\n" : "%06d\n"), fTable[number]);
	}
	return 0;
}