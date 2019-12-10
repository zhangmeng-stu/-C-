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

		//����ָ��������Ϊ
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		
		//��ֹ������--��ֹ���ÿ�������&��ֵ���������

#if 0
		//C++98��ֻ����������& private
	private:
		unique_ptr<(const unique_ptr<T>& up);
		unique_ptr<T>& operator=(const unique_ptr<T>& up);
#endif
		//C++11��
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