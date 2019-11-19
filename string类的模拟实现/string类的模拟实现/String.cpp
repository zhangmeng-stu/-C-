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
		//���캯��
		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//�������캯��
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String temp(s);
			this->Swap(temp);
		}
		//��ֵ���������
		String& operator=(String s)
		{
			this->Swap(s);
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
				Reserve(_capacity * 2);
			_str[_size++] == c;
			_str[_size] = '\0';
		}
		//+=����
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
		//
	private:
		char*  _str;
		size_t _capacity;
		size_t _size;
	};

}
