#include <iostream>
#include <vector>
using namespace std;


/*1.��ά����Ĳ���
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
˼·��������λ����ĳ��ȣ������ж�*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size();//��ά���������
		int col = array[0].size();//��ά���������
		int i = row - 1;
		int j = 0;
		while (i >= 0 && j<col)
		{
			if (target > array[i][j])
			{
				j++;
			}
			else if (target < array[i][j])
			{
				i--;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

/*2.�滻�ո�
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy
˼·�����ҳ��ո�
�����ҳ�û�пո���ַ�����ƶ��ո����
ֱ���ڿո����%20*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL)
			return; 
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
				str[i + 2 * count] = str[i];//�����λ��2��ʾ%20�е���λ
			else
			{
				count--;
				str[i + 2 * count] = '%';
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}

	}
};