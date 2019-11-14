#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.两种排序方法（字符串）
vector<string> vec;

//按照字典序排序
bool lexicographically()
{
	int i = 0;
	while ((i + 1) < vec.size())
	{
		if (vec[i].compare(vec[i + 1])>0)
			return 0;
		i++;
	}
	return 1;
}

//按照字符串大小排序
bool Lengths()
{
	int i = 0;
	while ((i + 1) < vec.size())
	{
		if (vec[i + 1].size() < vec[i].size())
			return 0;
		i++;
	}
	return 1;
}
int main()
{
	string str;
	int n,i = 0;
	bool b1, b2;
	cin >> n;
	while (i < n)
	{
		cin >> str;
		vec.push_back(str);
		i++;
	}
	b1 = lexicographically();
	b2 = Lengths();

	if (b1 && b2)
		cout << "both";
	else if (b1 && !b2)
		cout << "lexicographically";
	else if (!b1 && b2)
		cout << "Lengths";
	else
		cout << "none";

	return 0;
}

#endif

#if 0
/*2.正整数A和正整数B的最小公倍数是指能被A和B整除的最小的正整数值，
设计一个算法，求输入A和B的最小公倍数
*/

int main()
{
	int a, b,i;
	cin >> a >> b;
	for (i = a;; i++)
	{
		if (i%a == 0 && i%b == 0)
			break;
	}
	cout << i;
}

#endif

#if 0
//3.另类加法（不使用+）
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if (A == 0)
			return B;
		else if (B == 0)
			return A;
		else
			return addAB(A^B, (A&B) << 1);
	}
};

#endif 


#if 0
//测试
int fun(int a)
{
	int c = 1 << 5;
	a =a^ (1 << 5) - 1;
	return a;
}
int main()
{
	int n = fun(21);
	cout << n;
	return 0;
}

#endif

/*4.请编写一个函数（允许增加子函数），
计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，
要求不能走回头路，即：只能往右和往下走，不能往左和往上走。*/
/*思路
用递归来做，将右下角看做原点(0, 0)，左上角看做坐标(m, n)，
从(m, n)—>(0, 0)就分两步走：
往右走一步：f(m, n - 1)—>(0, 0) 加上下走一步：f(m - 1, n)—>(0, 0)
注意：但凡是触碰到边界，也就是说f(x, 0)或者f(0,x)都只有一条直路可走了，这里的x是变量哈。
f(m, n) = f(m, n - 1) + f(m - 1, n)*/

int func(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 1;
	}
	return func(m, n - 1) + func(m - 1, n);
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << func(m, n) << endl;
	}
	return 0;
}