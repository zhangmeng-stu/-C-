#include <iostream>
using namespace std;

/*养兔子
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
思路：菲波那切数列
*/
int main()
{
	int n;
	while (cin >> n)
	{
		long a[91];
		a[1] = 1;
		a[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		cout << a[n] << endl;
	}

	return 0;
}

/*一种消息接收并打印的结构设计
已知一个消息流会不断地吐出整数1 \sim N1∼N，但不一定按照顺序吐出。如果上次打印的数为i，
那么当i+1出现时，请打印i+1及其之后接收过的并且连续的所有数，直到1 \sim N1∼N全部接收并打印完，请设计这种接收并打印的结构
*/

#include <vector>
#include <queue>

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		arr[i] = 0;
	}
	int min = 1;
	int a;
	while (1)
	{
		cin >> a;
		if (a != min)
		{
			arr[a] = 1;
		}
		else
		{
			cout << min << " " << a << endl;
			min++;
			if (min == n + 1)
				break;
			while (arr[min])
			{
				cout << min << " " << a << endl;
				min++;
				if (min == n + 1)
					break;
			}
			if (min == n + 1)
				break;
		}
	}
	delete[]arr;
	return 0;
}