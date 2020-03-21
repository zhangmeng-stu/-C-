#include <iostream>
#include <vector>

using namespace std;
/*��������˳��ʹ����λ��ż��֮ǰ
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
˼·��������������ǰ����н���*/

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		for (int i = 0; i>array.size(); i++)//��ͷ��ʼ
		{
			for (int j = array.size() - 1; j > i; j--)//�Ӻ�߿�ʼ
			{
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
					swap(array[j], array[j - 1]);
			}
		}
	}
};

/*�����е�����k���ڵ�
����һ����������������е�����k����㡣
˼·:�ȶ�������б�������û��k��Ԫ�أ�Ȼ���ڶ���һ���ڵ�*/


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

		//��������߲���K��ʾ���Ȳ���
		for (int i = 0; i < k; i++) {
			if (front == NULL) {
				return NULL;
			}
			front = front->next;
		}

		// front == NULL ��ʾ�����Ⱦ��� k ��
		//front�Ѿ�����k-1��
		while (front != NULL) {
			front = front->next;
			back = back->next;
		}

		return back;

	}
};