#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
//1.���˴�����
/*һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)��
���һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
˼·��
 1 �� 1 ʱ�������ȿ� 1 2���������⣬��չһλ 1 2 2���������⣬��չһλ 1 2 2 2��������
 ��������һλ��1 2 2�����һλ������1 2 3�����������⣬��������һλ�� 1 2�����һλ
 ������1 3���������⣬�����޷���չ�����һλ������1 4���������⣬�ٴλ��������ޣ�
 ��������ʱ����Ϊ 4��
 2 �� 1 ʱ�������ȿ� 1 1 2 �������⣬��չһλ 1 1 2 2 �������⣬1 1 2 2 2 �����ϣ�����
 ����һλ������ 1 1 2 3�����ϣ��������� 1 1 2 4�����ϣ����ݣ�1 1 3����
 �õ���� 16�����ǻᷢ������ 2 ����������Ϊ�˷���û�м���ȫ�� 1 ���������������ֻ
 �� 1 ʱ��1 �ĸ��� - 1��ʹ���Ž�*/
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
	int n, numb, OneCont(0);//OneCont������¼1���ܸ���
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
	cont = OneCont - 1; //����1�����ȼ������
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


//2.�������ڵ�������ת��

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