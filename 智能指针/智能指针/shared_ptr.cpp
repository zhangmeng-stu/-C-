#include <iostream>
#include <mutex>

using namespace std;

namespace bite
{
	template < class T >
	class shared_ptr
	{
	public:
		//RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(nullptr)
		{
			if (_ptr)
			{
				_pMutex = new mutex;
				_pCount = new int(1);
			}
		}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			if (_pCount)
				AddRef();
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//�õ�ǰ��������Դ�Ͽ�
				Release();

				//��sp����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_pCount)
					AddRef();
			}
			return *this;
		}
		~shared_ptr()
		{
			Release();
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
		int use_count()
		{
			return *_pCount;
		}
	private:
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}
		int SubRef()
		{
			_pMutex->lock();
			--(*_pCount);
			_pMutex->unlock();

			return *_pCount;
		}
		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				delete _ptr;
				delete _pCount;

			}
		}
	protected:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex; //��֤�����İ�ȫ�ԣ�������
	};
}
//mutex�����Ա�֤�����İ�ȫ�� || ���Ա�֤shared_ptr�౾��İ�ȫ��
//�����ܱ�֤shared_ptr������Դ�����ݵİ�ȫ��

void TestFunc()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	bite::shared_ptr<int> sp3(new int);
	bite::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp1;
	cout << sp1.use_count() << endl;

	sp4 = sp1;
	cout << sp1.use_count() << endl;
}

int main()
{
	TestFunc();
	return 0;
}
