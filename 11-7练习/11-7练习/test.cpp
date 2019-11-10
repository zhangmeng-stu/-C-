#include <iostream>
#include <string>
#include <vector>
using namespace std;

//1.字符串中找出最长的数字串
//思路：遍历字符串，遇到数字后开始循环，直到不是数字后跳出循环，计算出数字的长度
//记录与保存最大长度

#if 0
int main()
{
	string str;
	while (cin >> str)  //循环输入
	{
		int i;
		int max = 0;
		string s1;
		string s2;
		for (i = 0; i < str.size(); i++)//遍历字符串
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				s1 += str[i];
				while (str[i] >= '0' && str[i] <= '9')
				{
					i++;
					s1 += str[i];
				}
				if (s1.size() > max)
				{
					max = s1.size();
					s2 = s1;
				}
				else if (s1.size() == max)
				{
					s2 += s1;
				}
			}
			s1.clear();
		}
		cout << s2 << ',' << max << endl;
	}
	return 0;
}

#endif

#if 0
//2.数组中出现次数最多的数字
//思路：遍历数组保存两个值，一是数组中一个数字，一个次数，遍历下一个数字时，
//若它与之前保存的数字相同，则次数加1，若次数为0，则保存下一个数字，并将次数置为1。
//遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
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

#endif



#if 0
//3.给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

void Trans(int m, int n)
{
	if (n<1 || n>16)
		return;
	if (m < 0)
	{
		m = -m;
		cout << "-";
	}
	vector<int> a;//存放转换后的数字
	while (m)
	{
		a.push_back(m%n);
		m = m / n;
	}

	vector<int>::reverse_iterator it = a.rbegin();//反向迭代器
	while (it != a.rend())
	{
		if (*it == 10)
			cout << "A";
		else if(*it == 11)
			cout << "B";
		else if (*it == 12)
			cout << "C";
		else if (*it == 13)
			cout << "D"; 
		else if (*it == 14)
			cout << "E";
		else if (*it == 15)
			cout << "F";
		else
			cout << *it;
		it++;
	}
	cout << endl;
}
int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	Trans(m, n);
	return 0;
}

#endif 

//计算糖果
//题目：
//A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
//A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
//现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。
int main()
{
	int a, b, c, d;
	int A, B, C;
	while (cin >> a >> b >> c >> d)
	{
		//a = A - B; b = B - C; c = A + B; d = B + C;
		A = (a + c) / 2;
		B = (b + d) / 2;
		C = (d - b) / 2;
		if (A - B == a && B - C == b && A + B == c && B + C == d)
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}