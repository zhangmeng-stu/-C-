
//�����ַ���
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void abs(char* start, char* end)
{
	while (start<end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
int main()
{
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	int i = 0;
	while (str[i])
	{
		int count = 0;
		while (str[i] != ' '&& str[i] != '\0')
		{
			i++;
			count++;
		}
		abs(&str[i - count], &str[i - 1]);
		while (str[i] == ' ')
		{
			i++;
		}
	}
	cout << str << endl;
	return 0;

}

//���������У�������������Ϊһ��������һ�������������в�������������Ƿǵ�����ǵݼ�����ġ�
//��һ������Ϊn����������A����������һ�������ǰ�����A��Ϊ���ɶ����������С�
#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec;
	int num = 0;
	int ret = 1;
	cin >> num;
	vec.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> vec[i];
	}
	for (int i = 1; i < num - 1; ++i)
	{
		if ((vec[i - 1] > vec[i] && vec[i] < vec[i + 1]) || (vec[i - 1] < vec[i] && vec[i] > vec[i + 1]))
		{
			ret++;
			if (i != num - 3)
				i++;
		}
	}
	cout << ret << endl;
	return 0;
}