#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*5.用两个栈实现队列
两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
思路：用栈1直接入数字，栈2实现出队列*/

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

/*6.旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
思路：遍历整个数组进行比较得到最小值*/
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
/*7.菲波那切数列
公式：F(n-2)+F(n-1)*/

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