#include <iostream>
using namespace std;

//排序

//快排  hoare法
int partition1(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];//选取最右边作为基准值
	while (begin < end)
	{
		//begin从头开始查找，遇到比基准值大的停下来
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		//end从末尾开始查找遇到比基准值小的停下来
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		//交换end与begin，然后继续查找
		int temp = array[begin];
		array[begin] = array[end];
		array[end] = temp;
	}
	//直到begin==end，交换begin与基准值
	int temp = array[begin];
	array[begin] = array[right];
	array[right] = temp;
	
	return begin;

}

//快排之挖坑法
int partition2(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];
	while (begin < end)
	{
		//begin从头开始查找,遇到比基准值大的停下来，
		
		while (begin < end&&array[begin] <= pivot)
		{
			begin++;
		}
		//将该元素移动到坑所在的位置，begin所在位置变为坑，end前移
		array[end] = array[begin];
		//end从末尾开始查找，遇到比基准值小的停下来，
	
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		//将该元素移动到坑所在的位置，end所在位置变为坑
		array[begin] = array[end];
		
	}
	//begin=end，将基准值移动到begin所指向的位置
	array[begin] = pivot;

	return begin; 
}

//快排之快慢指针
int parition3(int array[], int left, int right)
{
	int div = left;
	int i = left;
	//
	for (; i < right; i++)
	{
		//，如果小于基准值，
		//交换i与div，如果大于基准值，div不动，i继续向前移动
		if (array[i] < array[right])
		{
			int t = array[i];
			array[i] = array[div];
			array[div] = t;
			div++;
		}
	}
	//交换div与基准值元素
	int temp = array[div];
	array[div] = array[right];
	array[right] = temp;
	return div;
}