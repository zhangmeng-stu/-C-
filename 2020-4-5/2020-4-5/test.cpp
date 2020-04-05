#include <iostream>
#include <string>
using namespace std;

string pre, post;
typedef long long ll;
const int maxn = 25;
ll f[maxn], m;
void init() {
	f[0] = 1;
	for (int i = 1; i < maxn; i++) {
		f[i] = f[i - 1] * i;
	}
}
ll cal(int preL, int preR, int postL, int postR) {
	if (preL > preR) return 1;
	int left1 = preL + 1, left2 = postL, len, res = 1, cnt = 0;
	for (int i = left2; i < postR; i++) {
		if (post[i] == pre[left1]) {
			len = i - left2 + 1;
			cnt++;
			res *= cal(left1, left1 + len - 1, left2, left2 + len - 1);
			left1 += len;
			left2 += len;
		}
	}
	return f[m] / f[cnt] / f[m - cnt] * res; //必须先除，不然可能超
}
int main() {
	init();
	while (cin >> m && m) {
		cin >> pre >> post;
		cout << cal(0, pre.size() - 1, 0, post.size() - 1) << endl;
	}
	return 0;
}




#include<iostream>
#include<string>
using namespace std;


string Format(long long a, long long b)
{
	string tmp;
	if (a * b < 0)
		tmp += "(-";
	long long a1 = abs(a);
	long long b1 = abs(b);
	long long c = a1 / b1;
	long long d = a1 % b1;
	// 整除
	if (d == 0 && c != 0)
	{
		tmp += to_string(c);
	}
	// 只有分数形式
	else if (c == 0 && d != 0)
	{
		// 将分数 d / b1 化为最简形式
		long long i = d;
		while (i > 1)
		{
			if (d % i == 0 && b1 % i == 0)
			{
				d /= i;
				b1 /= i;
			}
			i--;
		}
		tmp += to_string(d);
		tmp += '/';
		tmp += to_string(b1);
	}
	else if (c == 0 && d == 0)
	{
		tmp += '0';
		return tmp;
	}
	else
	{
		tmp += to_string(c);
		tmp += ' ';
		// 将分数 d / b1 化为最简形式
		long long i = d;
		while (i > 1)
		{
			if (d % i == 0 && b1 % i == 0)
			{
				d /= i;
				b1 /= i;
			}
			i--;
		}
		tmp += to_string(d);
		tmp += '/';
		tmp += to_string(b1);
	}
	if (a * b < 0)
		tmp += ')';
	return tmp;
}
void Sum(long long a, long long b, long long c, long long d)
{
	cout << Format(a, b) << " + " << Format(c, d) << " = ";
	long long a1 = a * d + b * c;
	long long b1 = b * d;
	cout << Format(a1, b1) << endl;
}
void Dif(long long a, long long b, long long c, long long d)
{
	long long a1 = a * d - b * c;
	long long b1 = b * d;
	cout << Format(a, b) << " - " << Format(c, d) << " = " << Format(a1, b1) << endl;
}
void Mul(long long a, long long b, long long c, long long d)
{
	long long a1 = a * c;
	long long b1 = b * d;
	cout << Format(a, b) << " * " << Format(c, d) << " = " << Format(a1, b1) << endl;
}
void Dev(long long a, long long b, long long c, long long d)
{
	long long a1 = a * d;
	long long b1 = b * c;
	cout << Format(a, b) << " / " << Format(c, d) << " = ";
	if (b1 == 0)
	{
		cout << "Inf";
		return;
	}
	cout << Format(a1, b1);
}
int main()
{
	long long a, b, c, d;
	while (scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d) != EOF)
	{
		Sum(a, b, c, d);
		Dif(a, b, c, d);
		Mul(a, b, c, d);
		Dev(a, b, c, d);
	}



	return 0;
}