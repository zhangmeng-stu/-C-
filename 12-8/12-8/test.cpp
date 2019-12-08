#include <iostream>
#include <vector>
using namespace std;

#if 0
//1.�мٱң����أ�
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

//2.���������е���С������ɺ�
class Solution 
{
public:
	/**
	*	���������е���С������ɺ�
	*	���룺��������arr
	*	���أ����������е���С������ɺ�
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

//�Ǽ�����
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

//����/*��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
       /* ���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
���ڸ���һ�����������������������*/
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

//��̬��̨��
/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
1�������f(n) �������n��̨����һ��1,2,...n�׵� ��������
2��n = 1ʱ��ֻ��1��������f(1) = 1
3) n = 2ʱ�������������÷�ʽ��һ��1�׻���2�ף���ع鵽�����⣨1�� ��f(2) = f(2-1) + f(2-2)
4) n = 3ʱ�������������÷�ʽ��1�ס�2�ס�3�ף�
��ô���ǵ�һ������1�׺���ʣ�£�f(3-1);��һ������2�ף�ʣ��f(3-2)����һ��3�ף���ôʣ��f(3-3)
��˽�����f(3) = f(3-1)+f(3-2)+f(3-3)
5) n = nʱ������n�����ķ�ʽ��1�ס�2��...n�ף��ó����ۣ�
f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)

6) �������Ѿ���һ�ֽ��ۣ�����Ϊ�˼򵥣����ǿ��Լ����򻯣�
f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
���Եó���
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


//�쵽������
/*С���Ǻ�ϲ�����Լ�װ��������ģ������룩������Ҫ������ܳ������������̣����Ǿͽ���ȥ�ˡ�

���ڸ��������ǵ���������İ뾶�����ж�һ���ܷ�����ȥ��*/
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
