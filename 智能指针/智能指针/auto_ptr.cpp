#include <iostream>
using namespace std;

#if 0
//C++98:auto_ptr
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}

		//让类具有指针类似的行为
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
}

void TestFunc()
{
	//常规指针
	int a = 10;
	int* p1 = &a;
	int* p2(p1);

	*p1 = 100;
	*p2 = 200;
	bite::auto_ptr<int> ap1(new int);
	
	//解决方式：将资源转移
	bite::auto_ptr<int> ap2(ap1);
	*ap1 = 10;//会发生崩溃----ap1已经将资源转移给ap2，自已与资源断开联系

}

int main()
{
	TestFunc();
	return 0;
}
#endif

//改进：auto_ptr
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
				_owner = true;
		}

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//先处理以前旧资源
				if (_ptr && _owner)
					delete _ptr;
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}
		~auto_ptr()
		{
			if (_ptr && _owner)
				delete _ptr;
		}

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
		mutable bool _owner;   //资源真正拥有者（对资源具有释放的权利）
	};
}

void TestFunc2()
{
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);
	bite::auto_ptr<int> ap3;

	*ap1 = 10;
	*ap2 = 20;
	*ap3 = 30;
}

//int main()
//{
//	TestFunc();
//	return 0;
//}