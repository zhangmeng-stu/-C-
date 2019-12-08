#include <iostream>
#include <vector>
using namespace std;

#if 0
//1.有假币（称重）
int Func(int n)
{
	if (n == 1)
		return 0;
	if (n <= 3)
		return 1;
	else
		return Func((n + 2) / 3) + 1;
}
int main()
{
	int n;
	while (cin >> n&&n != 0)
	{
		cout << Func(n) << endl;
	}
	return 0;
}

#endif

//2.正数数组中的最小不可组成和
class Solution 
{
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) 
	{
		int sum = 0, min = arr[0];
		for (int i = 0; i < len; i++)
		{
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < len; i++)
		{
			for (int j = sum; j >= arr[i]; j--)
			{
				if (dp[j] < dp[j - arr[i]] + arr[i])
				dp[j] = dp[j - arr[i]] + arr[i];
				else
					dp[j] = dp[j];
			}

		}
		for (int i = min; i <= sum; i++)
		{
			if (i != dp[i])
				return i;
		}
		return sum + 1;
	}
};

//星际密码
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 10000
int passward(int n)
{
	int left = 0;
	int right = 1;
	int cur = 1;
	for (int i = 0; i<n; i++)
	{
		cur = left + right;
		left = right%MAX;
		right = cur % MAX;
	}
	return cur %MAX;
}
int main()
{
	int n, temp;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			cin >> temp;
			printf("%04d", passward(temp));
			//cout<<"%04d"<<passward(temp)<<endl;
		}
		cout << endl;
	}
	return 0;
}

//数根/*数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
       /* 比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
现在给你一个正整数，输出它的数根。*/
#include <iostream>
#include <string>
using namespace std;
int NumRoot(int n)
{
	int sum = 0;
	while (n / 10)
	{
		sum += n % 10;
		n = n / 10;
	}
	sum += n % 10;
	if (sum / 10 == 0)
		return sum;
	else
		return NumRoot(sum);
}
int main()
{
	string s;
	while (cin >> s)
	{
		int n = 0;
		for (int i = 0; i<s.size(); i++)
		{
			n += s[i] - '0';
		}
		cout << NumRoot(n) << endl;
	}
	return 0;
}

//变态跳台阶
/*一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
1）这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。
2）n = 1时，只有1种跳法，f(1) = 1
3) n = 2时，会有两个跳得方式，一次1阶或者2阶，这回归到了问题（1） ，f(2) = f(2-1) + f(2-2)
4) n = 3时，会有三种跳得方式，1阶、2阶、3阶，
那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3)
因此结论是f(3) = f(3-1)+f(3-2)+f(3-3)
5) n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)

6) 由以上已经是一种结论，但是为了简单，我们可以继续简化：
f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
可以得出：
f(n) = 2*f(n-1)*/

class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return -1;
		else if (number == 1)
			return 1;
		else
			return 2 * jumpFloorII(number - 1);
	}
};


//快到碗里来
/*小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。

现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。*/
#include <iostream>
using namespace std;

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14*r)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
