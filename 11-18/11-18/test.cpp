#include <iostream>
using namespace std;

#if 0
//1.查找组成一个偶数最接近的两个素数
bool Issushu(int n)
{
	if (n == 1 || n == 2)
		return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 2 != 0)
			return 0;
			int start = 0;
			int end = 0;
			for (int i = 0; i <= n / 2; i++)
			{
				if (Issushu(i) && Issushu(n - i))
				{
					if (i > start)
					{
						start = i;
						end = n - i;
					}
				}
			}
			cout << start << "\n" << end << endl;
		}
	return 0;
}

#endif


class Base
{
public:
	int bar(char x)
	{
		return (int)(x);
	}
	virtual int bar(int x)
	{
		return (2 * x);
	}
};
class Derived :public Base
{
public:
	int bar(char x)
	{
		return (int)(-x);
	}
	int bar(int x)
	{
		return (x / 2);
	}
};
int main()
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->bar((char)100));
	printf("%d", pObj->bar(100));
}