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
//隐式实例化
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
	//对于上面的实例化，编译器并不能通过，因为在编译期间
	//发现参数有两个类型，编译器不知道用哪一个当编译器看到该实例化时，
	//需要推演其实参类型 ,通过实参a1将T推演为int，
	//通过实参d1将T推演为double类型，但模板参数列表中只有一个T，    
	//编译器无法确定此处到底该将T确定为int 或者 double类型而报错

	//强制转化
	Add(1, (int)2.0);
	return 0;
}

//显示实例化
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
//非模板函数
int Add(int left, int right)
{
	return left + right;
}
//模板函数
template<typename T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化    
	Add(1, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数 
	return 0;
}
#endif

//类模板
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

// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表 
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
	//类模板实例化
	Seqlist<int> s1;
	s1.PushBack(1);
	s1.Seplistprint();
	return 0;

}
