#include <iostream>
using namespace std;

/*�Ա�����
NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
���ڸ���һ��ʱ�����䣬������������������ж��١�
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
{//�������ڵ�ͬ��
	days[2] = leepyear(year1) ? 29 : 28;
	if (month1<month2)//��������һ����1��
	{
		money += (days[month1] - day1 + 1)*mons[month1++];
		day1 = 1;
	}
	while (month1<month2)//��������
		money += days[month1] * mons[month1++];
	if (flag)//���굽��һ��1��1��
		money += days[12] * mons[12];
	return money;
}
int main()
{
	int year1, month1, day1, year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int money = 0;
		if (year1<year2)//��ͬ��
		{
			money = one(year1++, month1, day1, 12, money, 1);
			month1 = 1;
			while (year1<year2)//��������
				money += leepyear(year1++) ? 580 : 579;
		}
		money = one(year1, month1, day1, month2, money, 0) + (day2 - day1 + 1)*mons[month1];
		cout << money << endl;
	}
	return 0;
}

/*

NowCoder�ų��Լ��Ѿ���ס��1-100000֮�����е�쳲���������
Ϊ�˿���������������һ����n������˵����n��쳲���������
��Ȼ��쳲���������ܴ���ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��
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
	//����һ�ű����ڼ�¼쳲����������еĸ���ֵ
	int fTable[100001] = { 0, 1, 2 };
	for (int i = 3; i < 100001; ++i) {
		fTable[i] = fTable[i - 1] + fTable[i - 2];
		//��Ҫ��ÿ��������࣬��������
		fTable[i] = fTable[i] % 1000000;
	}
	int number = 0;
	//scanf����ֵΪ��ȷ������ݵı�����������һ��������û�гɹ���ȡ����ʱ����ʱ����-1
	while (scanf("%d", &number) != -1) {
		//��Ŀ��Щ�ӣ�number >= 29ʱǰ�油0,Ҫ��06d��������������λ��Ҫ��0��
		printf((number < 29 ? "%d\n" : "%06d\n"), fTable[number]);
	}
	return 0;
}