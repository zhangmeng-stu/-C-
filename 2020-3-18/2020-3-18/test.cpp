#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*5.������ջʵ�ֶ���
����ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
˼·����ջ1ֱ�������֣�ջ2ʵ�ֳ�����*/

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int temp = stack1.top();
				stack1.pop;
				stack2.push(temp);
			}
				int t = stack2.top();
				stack2.pop();
				return t;
		}
		int t = stack2.top();
		stack2.pop();
		return t;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

/*6.��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
˼·����������������бȽϵõ���Сֵ*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		for (int i = 0; i<rotateArray.size() - 1; i++)
		{
			if (rotateArray[i]>rotateArray[i + 1])
				return rotateArray[i + 1];
		}
		return 0;
	}
};
/*7.�Ʋ���������
��ʽ��F(n-2)+F(n-1)*/

class Solution {
public:
	int Fibonacci(int n) {
		if (n<2)
			return n;
		int a = 0, b = 1, result = 0;
		for (int i = 1; i < n; i++)
		{
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};