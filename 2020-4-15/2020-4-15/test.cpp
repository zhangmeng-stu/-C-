#include <iostream>
#include <string>
using namespace std;
#include <algorithm>



void judge(string&s1, string& s2)
{
	int len1 = 1, len2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	size_t i = 0;
	while (i < s2.size())
	{
		if (s1.find(s2[i]) == string::npos)
		{
			cout << "No" << endl;
			return;
		}

			len1 = (s1.rfind(s2[i]) - s1.find(s2[i]) + 1);
			len2 = (s2.rfind(s2[i]) - s2.find(s2[i]) + 1);
			if (len1 < len2)
			{
				cout << "No" << endl;
				return;
			}
			i++;
		 
		}
		cout << "Yes" << endl;
}
int main()
{
	string s1, s2;
	while (cin >> s1)
	{
		cin >> s2;
		judge(s1, s2);
	}
}


/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/
#include <vector>

//˼·1:����
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		sort(numbers.begin(), numbers.end());
		int middle = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == middle)
				count++;
		}
		return (count>numbers. size() / 2) ? count : 0;
	}
};

//˼·2
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
		{
			return 0;
		}
		//����ÿ��Ԫ�أ�����¼������
		int result = numbers[0];
		int count = 1;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
			{
				//����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				count = 1;
			}
			else if (numbers[i] == result)
			{
				++count;
			}
			else
			{
				--count;
			}
		}
		//�ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++count;
		}
		return (count>numbers.size() / 2) ? result : 0;
	}
};


/*

����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����

1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼����
����ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��
*/



#include <iostream>
#include <string.h>
using namespace std;

struct memory
{
	char s[100];
	int line;
	int count;
};
int main()
{
	char input[100];
	int line;
	int cnt = 0;
	memory record[1000];
	while (cin >> input >> line)
	{
		char *p = strrchr(input, '\\');
		p++;
		if (strlen(p) > 16)
		{
			p = p + strlen(p) - 16;
		}
		int flag = 0;

		for (int i = 0; i < cnt; i++)
		{
			if (strcmp(record[i].s, p) == 0)
			{
				if (record[i].line == line)
				{
					flag = 1;
					record[i].count++;
					break;
				}
			}

		}
		if (!flag)
		{
			strcpy(record[cnt].s, p);
			record[cnt].line = line;
			record[cnt].count = 1;
			cnt++;
		}
	}
	int j;
	if (cnt > 8)
		j = cnt - 8;
	else
		j = 0;
	for (; j < cnt; j++)
	{
		cout << record[j].s << ' ' << record[j].line << ' ' << record[j].count << endl;
	}
	return 0;
}