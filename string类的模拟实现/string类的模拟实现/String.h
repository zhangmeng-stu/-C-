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
		//构造函数
		String(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//放n个字符ch的元素（构造）
		String(size_t n, char ch)
			: _str(new char[n+1])
			,_size(n)
			, _capacity(n)
		{
				memset(_str, ch, _size);
				_str[_size] = '\0';
		}
		//拷贝构造函数
		String(const String& s)
			:_size(s._size)
			, _capacity(s._size)
		{
			_str = new char[_size+1];
			strcpy(_str, s._str);
		}
		//赋值运算符重载
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
		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		//iterator迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//modify
		//插入元素
		void PushBack(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		//+=重载
		//追加单个字符
		String& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

		//追加字符串
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
		//+=一个类类型对象
		String& operator+=(const String& s)
		{
			*this += s._str;
			return *this;
		}
		
		//清除
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		//交换
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		//acess
		//下标[]运算符重载，访问任意位置元素
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		//const类型下标[]运算符重载，访问任意位置元素
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		//capacity
		//有多少个有效字符
		size_t size()const
		{
			return _size;
		}
		//底层容量的大小
		size_t capacity()const
		{
			return _capacity;
		}
		//判断string是不是空
		bool empty()const
		{
			return 0 == _size;
		}
		//改变当前string类的有效元素个数
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
		//扩容
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
		//获取c格式的字符串
		const char* c_str()const
		{
			return _str;
		}
		//从头开始查找元素
		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		//从后面开始查找元素
		size_t rfind(char ch)
		{
			for (int  i = _size-1; i <= 0; i--)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		//获取子串
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

	//利用迭代器打印String中的元素
	bit::String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
	}
	cout << endl;

	//范围for
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}