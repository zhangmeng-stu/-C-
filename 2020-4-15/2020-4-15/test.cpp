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
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include <vector>

//思路1:排序
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

//思路2
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
		{
			return 0;
		}
		//遍历每个元素，并记录次数；
		int result = numbers[0];
		int count = 1;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
			{
				//更新result的值为当前元素，并置次数为1
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
		//判断result是否符合条件，即出现次数大于数组长度的一半
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

开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理：

1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），
对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径
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