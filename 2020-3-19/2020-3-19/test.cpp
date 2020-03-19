#include <iostream>

using namespace std;
/*8.跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
思路：
a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);
b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)
c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2)
f1 = 1,f2 = 2,f3 = 3,f4 = 5(跳法)
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

/*9.变态跳台阶
c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 
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

/*10.矩形覆盖
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法
f(1) = 1;
f(2) = 2
f(3) = 3=f(1)+f(2);
f(4) = 5
f(5) = 8
推出为菲波那切数列*/
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

/*11.二进制中1的个数
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
思路：把数字逐次右移然后&1，判断这个是不是1*/

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

/*12.数值的整数次方
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
思路：利用pow() pow() 函数用来求 x 的 y 次方的值。
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