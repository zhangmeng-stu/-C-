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
		//����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴���Ҫ����
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

//����
void TestString()
{
	String s1("hello world!");
	String s2(s1);
}
           
#endif


#if 0
//��ͳ��д����String��

class String
{
public:
	//���캯��
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
	//�������캯��
	String(const String& s)
		:_str(new char[strlen(s._str)]+1)
	{
		strcpy(_str, s._str);
	}
	//��ֵ���������
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
	//��������
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
	//���캯��
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//�������캯��
	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp);
	}
	//��ֵ���������
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	//��������
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