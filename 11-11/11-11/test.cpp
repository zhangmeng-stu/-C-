#include <iostream>
#include <string>
using namespace std;


#if 0
//1.连续最大和
//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
//思路：从第二个数开始找，如果第一个数小于0，直接不要
int main()
{
	int n ;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) //创建数组
	{
		cin >> a[i];
	}
	int sum = a[0];
	int max = a[0];
	//从第二个数开始寻找使和最大
	for (int i = 1; i < n; ++i)
	{
		if (sum >= 0)
		{
			sum = sum + a[i];
		}
		else
		{
			sum = a[i];
		}
		if (max < sum)
			max = sum;
	}
	cout << max;
	return 0;
}

#endif


//2.统计回文
//输入两个字符串，把str2插入str1中统计回文次数
#if 0
bool HW(string str1)
{
	int length = str1.length();
	for (int i = 0; i < length; i++)
	{
		if (str1[i] != str1[length - 1])
			return false;
		length = length - 1;
	}
	return true;
}
int main()
{
	string str1, str2, temp;
	int count, len;
	while (cin >> str1 >> str2)
	{
		count = 0;
		temp = str1;//备份原始字符串，插入会破坏
		len = str1.length() + 1;
		for (int i = 0; i < len; i++)
		{
			str1 = temp;
			str1.insert(i, str2);
			if (HW(str1))
			{
				count = count + 1;
			}
		}
		cout << count << endl;
	}
	return 0;
}

#endif


//3.字符串转换成整数
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

#if 0

class Solution 
{
public:
	int StrToInt(string str) 
	{
		if (str.empty())
		{
			return 0;
		}
		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';//转换公式
	}
		return symbol *sum;
	}

};

#endif

//4.二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为 :
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。

#if 0
int main()
{
	int W, H, i, j, count = 0;
	cin >> W >> H;
	if (W % 4 == 0 || H % 4 == 0)
	{
		count = W*H / 2;
	}
	else if (W % 2 == 0 && H % 2 == 0)
	{
		count = (W*H / 4 + 1) * 2;
	}
	else
	{
		count = W*H / 2 + 1;
	}
	cout << count << endl;
	return 0;
}
#endif

//int main()
//{
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//
//}


int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 3) << "," << (*p)[2] << endl;
	return 0;
}