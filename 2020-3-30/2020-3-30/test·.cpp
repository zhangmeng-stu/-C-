#include <iostream>
using namespace std;

/*分解因素
所谓因子分解，就是把给定的正整数a，
分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,
并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 
先给出一个整数a，请输出分解后的因子。
思路：第一个while循环判断2，第二个while循环判断整除2之后的数字
*/

//int main1()
//{
//	int a = 0, i = 0;
//	while (cin >> a)
//	{
//		cout << a << " = ";
//		i = 2;
//		while (1)
//		{
//			if (a%i == 0)
//			{
//				cout << i;
//				a = a / i;
//				break;
//			}
//			i++;
//		}
//		while (a != 1)
//		{
//			i = 2;
//			while (1)
//			{
//				if (a%i == 0)
//				{
//					cout << " * " << i;
//					a = a / i;
//					break;
//				}
//				i++;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}
//

/*美国节日
*/
#include <cstdio>

int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
	{
		week = 7;
	}
	return week;
}
int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1);
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
	return day;
}

//元旦
void new_year_day(int year)
{
	cout << year << "-01" << "-01" << endl;
}
//马丁.路德.金纪念日
void martin_luther_king_day(int year)
{
	
	cout << year << "-01" << "-"<<day_of_demand(year, 1, 3, 1) << endl;
}
//总统日
void president_day(int year)
{
	cout << year << "-02-" << day_of_demand(year, 2, 3, 1) << endl;
}
//阵亡将士纪念日
void memorial_day(int year)
{
	int week = day_of_week(year, 6, 1);
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	cout << year << "-05-" << day << endl;
}
//美国国庆
void independence_day(int year)
{
	cout << year << "-07" << "-04" << endl;
}
//劳动节
void labor_day(int year)
{
	cout << year << "-09-0" << day_of_demand(year, 9, 1, 1) << endl;
}

//感恩节
void thanks_giving_day(int year)
{
	cout << year << "-11-" << day_of_demand(year, 11, 4, 4) << endl;
}
//圣诞节
void christmas_day(int year)
{
	cout << year << "-12" << "-25" << endl;
}
void holidaay_of_usa(int year)
{
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas_day(year);
}
int main()
{
	int year;
	while (cin >> year)
	{
		holidaay_of_usa(year);
		cout << endl;
	}
}