#include <iostream>
#include <string>
using namespace std;


//1.计算两个字符串的最大公共字串的长度
int main()
{
	string str1, str2, temp;
	int t = 0, dis = 0;
	while (cin >> str1 >> str2)
	{
		int len = str1.length();
		for (int i = len; i > 1; i--)
		{
			for (int j = 0; j < len; j++)
			{
				if (i + j <= len)
				{
					temp = str1.substr(j, i);
					t = str2.find(temp);
					if (t != -1 && temp.length()>dis)
						dis = temp.length();
				}
			}
		}
		cout << dis << endl;
	}
}


#if 0
//2.字符串反转
int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = str.size() - 1; i >= 0; i--)
			cout << str[i];
	}
	return 0;
}
#endif