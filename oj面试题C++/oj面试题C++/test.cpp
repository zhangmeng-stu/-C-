
//1.��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
//����ÿ����һ�ζ��󣬾͵���һ�ι��캯��
class Solution
{
	class Temp
	{
	public:
		Temp()
		{
			count++;
			sum += count;
		}
		static void Earse()
		{
			count = 0; sum = 0;

		}
		static int GetSum()
		{
			return sum;
		}
	private:
		static int  count;
		static int sum;
	};

public:
	int Sum_Solution(int n) {
		Temp::Earse();
		Temp* p = new Temp[n];
		delete[]p;

		return Temp::GetSum();
	}
};
int Solution::Temp::count = 0;
int Solution::Temp::sum = 0;

//�������ڵ�������ת��
#include <iostream>
using namespace std;
bool Isleapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}
int daysofmonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && Isleapyear(year) == true)
	{
		days[month] += 1;
	}
	return days[month];
}
bool Istrue(int year, int month, int day)
{
	if (year > 0 &&
		(month > 0 && month < 13) &&
		(day > 0 && day <= daysofmonth(year, month)))
	{
		return true;
	}
	return false;
}
int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
	{
		//�ж�����������Ƿ�Ϸ�
		if (Istrue(year, month, day) == false)
		{
			return -1;
		}
		int days1[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int days2[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int totaldays = 0;
		for (int i = 1; i<month; i++)
		{
			if (Isleapyear(year) == true)
			{
				totaldays = totaldays + days2[i];
			}
			else
			{
				totaldays = totaldays + days1[i];
			}
		}
		totaldays += day;
		cout << totaldays << endl;
	}

	return 0;
}