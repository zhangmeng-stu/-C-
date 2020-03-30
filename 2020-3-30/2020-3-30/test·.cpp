#include <iostream>
using namespace std;

/*�ֽ�����
��ν���ӷֽ⣬���ǰѸ�����������a��
�ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an,
���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ 
�ȸ���һ������a��������ֽ������ӡ�
˼·����һ��whileѭ���ж�2���ڶ���whileѭ���ж�����2֮�������
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

/*��������
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

//Ԫ��
void new_year_day(int year)
{
	cout << year << "-01" << "-01" << endl;
}
//��.·��.�������
void martin_luther_king_day(int year)
{
	
	cout << year << "-01" << "-"<<day_of_demand(year, 1, 3, 1) << endl;
}
//��ͳ��
void president_day(int year)
{
	cout << year << "-02-" << day_of_demand(year, 2, 3, 1) << endl;
}
//������ʿ������
void memorial_day(int year)
{
	int week = day_of_week(year, 6, 1);
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	cout << year << "-05-" << day << endl;
}
//��������
void independence_day(int year)
{
	cout << year << "-07" << "-04" << endl;
}
//�Ͷ���
void labor_day(int year)
{
	cout << year << "-09-0" << day_of_demand(year, 9, 1, 1) << endl;
}

//�ж���
void thanks_giving_day(int year)
{
	cout << year << "-11-" << day_of_demand(year, 11, 4, 4) << endl;
}
//ʥ����
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