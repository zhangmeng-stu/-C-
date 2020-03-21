#include <iostream>
#include <vector>

using namespace std;
/*调整数组顺序使奇数位于偶数之前
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
思路：遍历整个数组前后进行交换*/

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		for (int i = 0; i>array.size(); i++)//从头开始
		{
			for (int j = array.size() - 1; j > i; j--)//从后边开始
			{
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
					swap(array[j], array[j - 1]);
			}
		}
	}
};

/*链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个结点。
思路:先对链表进行遍历看有没有k个元素，然后在定义一个节点*/


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *front = pListHead;
		ListNode *back = pListHead;

		//如果链表走不到K表示长度不够
		for (int i = 0; i < k; i++) {
			if (front == NULL) {
				return NULL;
			}
			front = front->next;
		}

		// front == NULL 表示链表长度就是 k 个
		//front已经走了k-1步
		while (front != NULL) {
			front = front->next;
			back = back->next;
		}

		return back;

	}
};