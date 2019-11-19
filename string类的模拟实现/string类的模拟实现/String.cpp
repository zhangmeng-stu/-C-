#pragma once
#include <iostream>
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
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//拷贝构造函数
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String temp(s);
			this->Swap(temp);
		}
		//赋值运算符重载
		String& operator=(String s)
		{
			this->Swap(s);
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
				Reserve(_capacity * 2);
			_str[_size++] == c;
			_str[_size] = '\0';
		}
		//+=重载
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		//
		void Append(const char* str)
		{

		}
		//
		String& operator+=(const char* str)
		{

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
		//
	private:
		char*  _str;
		size_t _capacity;
		size_t _size;
	};

}
