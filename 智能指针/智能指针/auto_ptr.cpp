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

		//�������ָ�����Ƶ���Ϊ
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
	//����ָ��
	int a = 10;
	int* p1 = &a;
	int* p2(p1);

	*p1 = 100;
	*p2 = 200;
	bite::auto_ptr<int> ap1(new int);
	
	//�����ʽ������Դת��
	bite::auto_ptr<int> ap2(ap1);
	*ap1 = 10;//�ᷢ������----ap1�Ѿ�����Դת�Ƹ�ap2����������Դ�Ͽ���ϵ

}

int main()
{
	TestFunc();
	return 0;
}
#endif

//�Ľ���auto_ptr
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
				//�ȴ�����ǰ����Դ
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
		mutable bool _owner;   //��Դ����ӵ���ߣ�����Դ�����ͷŵ�Ȩ����
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