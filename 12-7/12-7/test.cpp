#include <iostream>
using namespace std;

#if 0
//1.不用加减乘除做加法
class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0)
		{
			int sum = num1 ^num2;
			num2 = (num1 &num2) << 1;
			num1 = sum;
		}
		return num1;
	}
};


//2.三角形
#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b >c && b + c > a && a + c >b)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
#endif

#if 0
//3. 奇数位上都是奇数或者偶数位上都是偶数

class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i<len && j <len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};

#endif

//4.猴子分桃
#include <algorithm>
int main()
{
	int n;
	while (cin >> n&& n>0)
	{
		cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
	}
	return 0;
}
