#include <iostream>
using namespace std;

#if 0
//1.���üӼ��˳����ӷ�
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


//2.������
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
//3. ����λ�϶�����������ż��λ�϶���ż��

class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
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

//4.���ӷ���
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
