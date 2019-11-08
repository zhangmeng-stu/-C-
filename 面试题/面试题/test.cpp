
//倒置字符串
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

//排序子序列：定义序子序列为一个数组中一段连续的子序列并且这段子序列是非递增或非递减排序的。
//有一个长度为n的整数数组A。他现在有一个任务是把数组A分为若干段排序子序列。
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