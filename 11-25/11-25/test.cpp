#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.������ǵı���
//˼·��1.�ҹ��ɣ����֣�����������ʾ�Ļ�����1�е�1�������������
//�����ڵ�n��Ԫ��λ�ã�n�����кţ�
// 2.��n�е�Ԫ�صĵ�һ�������һ����Ҫ��ǰ��ֵΪ1.�����е�Ԫ�أ�����һ���⣬���չ�ʽ
// a[i][j]=a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
int printYH(int n)
{
	vector<vector<int>> a(n, vector<int>(2 * n - 1, 0));
	a[0][n - 1] = a[n - 1][0] = a[n - 1][2 * n - 2] = 1;
	if (n < 2)
	{
		return -1;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < 2 * n - 2; ++j)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
	}
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		if (a[n - 1][i] != 0 && a[n - 1][i] % 2 == 0)
			return i + 1;
	}
	return 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << printYH(n) << endl;
	}
}
#endif

//���������
string Plus(string &str1, string &str2)
{
	string result = "";
	int s1 = str1.size();
	int s2 = str2.size();
	if (s1 == 0)
		return str2;
	if (s2 == 0)
		return str1;

	int t = s1 > s2 ? s1 : s2;
	for (int i = t - s1 - 1; i >= 0; i--)
		str1 = '0' + str1;
	for (int i = t - s2 - 1; i >= 0; i--)
		str2 = '0' + str2;

	int flag = 0;
	int temp;
	for (int i = t - 1; i >= 0; i--)
	{
		temp = (str1[i] - '0') + (str2[i] - '0') + flag;
		result = char((temp % 10) + '0') + result;
		flag = temp / 10;
	}
	if (flag == 1)
		result = '1' + result;
	return result;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << Plus(str1, str2) << endl;
	}
	return 0;
}

#if 0
#include <iostream>
#include <string>

using namespace std;

string addlong(string &str1, string &str2)
{
	string result = "";
	int s1 = str1.size();
	int s2 = str2.size();
	if (s1 == 0)
		return str2;
	if (s2 == 0)
		return str1;

	// ������һ��
	int t = s1 > s2 ? s1 : s2;
	for (int i = t - s1 - 1; i >= 0; i--)
		str1 = '0' + str1;
	for (int i = t - s2 - 1; i >= 0; i--)
		str2 = '0' + str2;

	int flag = 0;  // ��λ��־
	int temp;
	for (int i = t - 1; i >= 0; i--)
	{
		temp = (str1[i] - '0') + (str2[i] - '0') + flag;
		result = char((temp % 10) + '0') + result;
		flag = temp / 10;
	}
	if (flag == 1)
		result = '1' + result;
	return result;
}


int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << addlong(str1, str2) << endl;
	}
}
#endif
