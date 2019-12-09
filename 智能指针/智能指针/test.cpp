#include <iostream>
#include <vector>
using namespace std;

#if 0
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1>end1)
		tmp[index++] = a[begin1++];
	while (begin2<end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void Mergesort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);

}

int main()
{
	int a[5] = { 4, 5, 2, 3, 1 };
	Mergesort(a, 5);
	return 0;
}
#endif

template<class T>
class Smartptr
{
public:
	Smartptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~Smartptr()
	{
		if (_ptr)
			delete _ptr;
	}
	//让该类的对象具有指针类似的行为
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
protected:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestFunc1()
{
	Smartptr<int> sp(new int);
	*sp = 100;
	//解引用
	Smartptr<A> sp1(new A);
	sp1->a = 10;
	sp1->b = 20;
	sp1->c = 30;
}

//int main()
//{
//	TestFunc1();
//	return 0;
//}