#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace bit
{
	class String
	{
	public:
		typedef char* iterator;
	public:
		//���캯��
		String(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//��n���ַ�ch��Ԫ�أ����죩
		String(size_t n, char ch)
			: _str(new char[n+1])
			,_size(n)
			, _capacity(n)
		{
				memset(_str, ch, _size);
				_str[_size] = '\0';
		}
		//�������캯��
		String(const String& s)
			:_size(s._size)
			, _capacity(s._size)
		{
			_str = new char[_size+1];
			strcpy(_str, s._str);
		}
		//��ֵ���������
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* str = new char[s._size + 1];
				strcpy(str, s._str);
				delete _str;
				_str = str;
				_size = s._size;
				_capacity = _size;
			}
			return *this;
		}
		//��������
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		//iterator������
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//modify
		//����Ԫ��
		void PushBack(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		//+=����
		//׷�ӵ����ַ�
		String& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

		//׷���ַ���
		String& operator+=(const char* str)
		{
			size_t len = strlen(str);
			size_t newSize = size() + len;
			if (capacity() < newSize)
			{
				reserve(newSize);
			}
			strcat(_str, str);
			_size = newSize;
			return *this;
		}
		//+=һ�������Ͷ���
		String& operator+=(const String& s)
		{
			*this += s._str;
			return *this;
		}
		
		//���
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		//����
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		//acess
		//�±�[]��������أ���������λ��Ԫ��
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		//const�����±�[]��������أ���������λ��Ԫ��
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		//capacity
		//�ж��ٸ���Ч�ַ�
		size_t size()const
		{
			return _size;
		}
		//�ײ������Ĵ�С
		size_t capacity()const
		{
			return _capacity;
		}
		//�ж�string�ǲ��ǿ�
		bool empty()const
		{
			return 0 == _size;
		}
		//�ı䵱ǰstring�����ЧԪ�ظ���
		void resize(size_t newSize, char ch = char())
		{
			size_t oldsize = _size;
			if (newSize > oldsize)
			{
				if (newSize < _capacity)
				{
					reserve(_capacity);
				}
				memset(_str + _size, ch, newSize - oldsize);
			}
			_size = newSize;
			_str[_size] = '\0';
		}
		//����
		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char *str = new char[newCapacity + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = newCapacity;

			}
		}
		//��ȡc��ʽ���ַ���
		const char* c_str()const
		{
			return _str;
		}
		//��ͷ��ʼ����Ԫ��
		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		//�Ӻ��濪ʼ����Ԫ��
		size_t rfind(char ch)
		{
			for (int  i = _size-1; i <= 0; i--)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		//��ȡ�Ӵ�
		String substr(size_t pos = 0, size_t n = npos)
		{
			if (n == npos)
				n = size() - pos;
			String strRet;
			strRet.reserve(n);
			strncpy(strRet._str, _str + pos, n);
			strRet._size = n;
			strRet._str[n] = '\0';
			return strRet;
		}

		friend ostream& operator<<(ostream&_cout, const String& s)
		{
			_cout << s.c_str();
			return _cout;
		}
	private:
		char*  _str;
		size_t _capacity;
		size_t _size;

		static size_t npos;
	};
	size_t String::npos = 0;
}


void TestBitString()
{
	bit::String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('worl');
	s1 += 'd';
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	//���õ�������ӡString�е�Ԫ��
	bit::String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
	}
	cout << endl;

	//��Χfor
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}