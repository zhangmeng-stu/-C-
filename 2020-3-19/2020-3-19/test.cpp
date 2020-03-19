#include <iostream>

using namespace std;
/*8.��̨��
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
˼·��
a.�������������1�׻���2�ף���ô�ٶ���һ��������һ�ף���ôʣ�µ���n-1��̨�ף�������f(n-1);
b.�ٶ���һ��������2�ף���ôʣ�µ���n-2��̨�ף�������f(n-2)
c.��a\b������Եó�������Ϊ: f(n) = f(n-1) + f(n-2)
f1 = 1,f2 = 2,f3 = 3,f4 = 5(����)
*/

class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 0)
			return -1;
		else if (number < 3)
			return number;
		else
			return jumpFloor(number - 1) + jumpFloor(number - 2);

	}
};

/*9.��̬��̨��
c.��a\b������Եó�������Ϊ: f(n) = f(n-1) + f(n-2) 
n =1,f(1) =1;
f(2) = f(1)+f(1)
f(3) = f(2)+f(1)+f(0)
f(n-1) =  f(1)+f(2)+....f(n-1)
f(n) = f(1)+f(2)+....f(n-1)+f(n)*/

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

/*10.���θ���
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ���
f(1) = 1;
f(2) = 2
f(3) = 3=f(1)+f(2);
f(4) = 5
f(5) = 8
�Ƴ�Ϊ�Ʋ���������*/
class Solution {
public:
	int rectCover(int number) {
		if (number < 1)
			return 0;
		else if (number == 1 || number == 2)
			return number;
		else
			return rectCover(number - 1) + rectCover(number - 2);
	}
};

/*11.��������1�ĸ���
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
˼·���������������Ȼ��&1���ж�����ǲ���1*/

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n >> i & 1)
				count++;
		}
		return count;
	}
};

/*12.��ֵ�������η�
����һ��double���͵ĸ�����base��int���͵�����exponent��
��base��exponent�η���
˼·������pow() pow() ���������� x �� y �η���ֵ��
*/

class Solution {
public:
	double Power(double base, int exponent) {
		double b;
		if (exponent >= 0)
			b = pow(base, exponent);
		else
		{
			b = pow(base, -exponent);
			b = 1 / b;
		}
		return b;

	}
};