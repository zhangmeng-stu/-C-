#include <iostream>
using namespace std;


//ֱ�Ӳ�������
//�������䣺[0,i)
//�������䣺[i,size)
void insertSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		for (j = i - 1; k < array[j] && j >= 0; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = k;
	}
}
