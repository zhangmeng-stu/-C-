#include <iostream>
#include <vector>
using namespace std;


/*1.二维数组的查找
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
思路：给出二位数组的长度，进行判断*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size();//二维数组的行数
		int col = array[0].size();//二维数组的列数
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

/*2.替换空格
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
思路：先找出空格
倒着找出没有空格的字符向后移动空格个数
直接在空格处添加%20*/
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
				str[i + 2 * count] = str[i];//向后移位的2表示%20中的两位
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