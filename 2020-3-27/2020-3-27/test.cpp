#include <iostream>
using namespace std;

//����

//����  hoare��
int partition1(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];//ѡȡ���ұ���Ϊ��׼ֵ
	while (begin < end)
	{
		//begin��ͷ��ʼ���ң������Ȼ�׼ֵ���ͣ����
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		//end��ĩβ��ʼ���������Ȼ�׼ֵС��ͣ����
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		//����end��begin��Ȼ���������
		int temp = array[begin];
		array[begin] = array[end];
		array[end] = temp;
	}
	//ֱ��begin==end������begin���׼ֵ
	int temp = array[begin];
	array[begin] = array[right];
	array[right] = temp;
	
	return begin;

}

//����֮�ڿӷ�
int partition2(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];
	while (begin < end)
	{
		//begin��ͷ��ʼ����,�����Ȼ�׼ֵ���ͣ������
		
		while (begin < end&&array[begin] <= pivot)
		{
			begin++;
		}
		//����Ԫ���ƶ��������ڵ�λ�ã�begin����λ�ñ�Ϊ�ӣ�endǰ��
		array[end] = array[begin];
		//end��ĩβ��ʼ���ң������Ȼ�׼ֵС��ͣ������
	
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		//����Ԫ���ƶ��������ڵ�λ�ã�end����λ�ñ�Ϊ��
		array[begin] = array[end];
		
	}
	//begin=end������׼ֵ�ƶ���begin��ָ���λ��
	array[begin] = pivot;

	return begin; 
}

//����֮����ָ��
int parition3(int array[], int left, int right)
{
	int div = left;
	int i = left;
	//
	for (; i < right; i++)
	{
		//�����С�ڻ�׼ֵ��
		//����i��div��������ڻ�׼ֵ��div������i������ǰ�ƶ�
		if (array[i] < array[right])
		{
			int t = array[i];
			array[i] = array[div];
			array[div] = t;
			div++;
		}
	}
	//����div���׼ֵԪ��
	int temp = array[div];
	array[div] = array[right];
	array[right] = temp;
	return div;
}