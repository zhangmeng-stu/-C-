#pragma warning(disable:4996)
#include <iostream>
#include <assert.h.>
using namespace std;

#if 0
class String
{
public:
	String(const char* str = "")
	{
		//构造string类对象时，如果传递nullptr指针，认为程序非法，此处需要断言
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

//测试
void TestString()
{
	String s1("hello world!");
	String s2(s1);
}
           
#endif


#if 0
//传统版写法的String类

class String
{
public:
	//构造函数
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//拷贝构造函数
	String(const String& s)
		:_str(new char[strlen(s._str)]+1)
	{
		strcpy(_str, s._str);
	}
	//赋值运算符重载
	String& operator = (const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	//析构函数
	~String()
	{
		if (_str)
		{
			delete _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
}
#endif

class String
{
public:
	//构造函数
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//拷贝构造函数
	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp);
	}
	//赋值运算符重载
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	//析构函数
	~String()
	{
		if (_str)
		{
			delete _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};