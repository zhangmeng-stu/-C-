#include <iostream>
using namespace std;

namespace bite
{
	template<class T>
	class unique_ptr
	{
		//RAII
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}

		//具有指针类似行为
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		
		//防止被拷贝--禁止调用拷贝构造&赋值运算符重载

#if 0
		//C++98：只声明不定义& private
	private:
		unique_ptr<(const unique_ptr<T>& up);
		unique_ptr<T>& operator=(const unique_ptr<T>& up);
#endif
		//C++11中
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;
	protected:
		T* _ptr;
	};
}

void TestFunc3()
{
	bite::unique_ptr<int> up1(new int);
	bite::unique_ptr<int> up2;
}

//int main()
//{
//	TestFunc();
//	return 0;
//}