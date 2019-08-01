#if 0
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
char Add(char left, char right)
{
	return left + right;
}
template<class T>
T Add(T left, T right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	return 0;
}
#endif
#if 0
//��ʽʵ����
template<typename T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	//Add(1,2.0)
	//���������ʵ������������������ͨ������Ϊ�ڱ����ڼ�
	//���ֲ������������ͣ���������֪������һ����������������ʵ����ʱ��
	//��Ҫ������ʵ������ ,ͨ��ʵ��a1��T����Ϊint��
	//ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��    
	//�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����

	//ǿ��ת��
	Add(1, (int)2.0);
	return 0;
}

//��ʾʵ����
template<typename T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	Add <int>(1, 2.0);
	return 0;
}
#endif
#if 0
//��ģ�庯��
int Add(int left, int right)
{
	return left + right;
}
//ģ�庯��
template<typename T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����    
	Add(1, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add���� 
	return 0;
}
#endif

//��ģ��
#include <iostream>
using namespace std;
template<class T>

class Seqlist
{
public:
	Seqlist(size_t capacity = 10)
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	~Seqlist()
	{
		if (_array)
		{
			delete[] _array;
			_capacity = _size = 0;
		}
	}
	void PopBack();
	void PushBack(const T& data);
	size_t Size()
	{
		return _size;
	}
	size_t Capacity()
	{
		return _capacity;
	}

	void Seplistprint()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << endl;
		}
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б� 
template<class T>
void Seqlist<T>::PushBack(const T& data)
{
	_array[_size++] = data;
}

template<class T>
void Seqlist<T>::PopBack()
{
	_size--;
}

int main()
{
	//��ģ��ʵ����
	Seqlist<int> s1;
	s1.PushBack(1);
	s1.Seplistprint();
	return 0;

}
