#include "string.h"
#include "malloc.h"
#include <iostream>
using namespace std;
#if 0
//构造函数
class Time
{
public:
	Time()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	////无参的构造函数
	//Date()
	//{}
	////有全缺省值的构造函数
	//Date(int year = 2019, int month = 7, int day = 27)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
#endif
#if 0
//析构函数
class String
{
public:
	String(const char* str = "hahaha")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		free(_str);
	}
private:
	char* _str;
};
#endif

#if 0
//拷贝构造函数
class Date
{
public:
	Date(int year = 2017, int month = 7, int day = 27)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int mian()
{
	Date d1;
	Date d2(d1);
	return 0;
}
#endif

#if 0
//运算符重载
class Date
{
public:
	Date(int year = 2017, int month = 7, int day = 27)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//+重载
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}
	//前置++重载
	Date& operator++()
	{

		_day+=1;
		return *this;
	}
	//后置++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	//赋值运算符=重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	return 0;
}
#endif

#if 0
//const成员函数
class Date
{
public:
	void Display()const
	{
		cout << _year << "-" <<_month;
		cout << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif

//取地址&重载
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	return 0;
}