#include "string.h"
#include "malloc.h"
#include <iostream>
using namespace std;
#if 0
//���캯��
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
	////�޲εĹ��캯��
	//Date()
	//{}
	////��ȫȱʡֵ�Ĺ��캯��
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
//��������
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
//�������캯��
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
//���������
class Date
{
public:
	Date(int year = 2017, int month = 7, int day = 27)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//+����
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}
	//ǰ��++����
	Date& operator++()
	{

		_day+=1;
		return *this;
	}
	//����++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	//��ֵ�����=����
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
//const��Ա����
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

#if 0
//ȡ��ַ&����
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
#endif


#if 0
//�б��ʼ��
class Time
{
public:
	Time(int hour)
		:_hour(hour)
		
	{}
	
private:
	int _hour;

};
class Date
{
public:
	Date(int year, int month, int day,int d,int hour)
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(10)
		, _d(d)
		, _hour(hour)
	{}
private:
	int _year;
	int _month;
	int _day;
	const int  _t;//const
	int& _d;//����
	Time _hour;//û��Ĭ�Ϲ��캯��
};
#endif

#if 0
//��������д��������������
class A
{
public:
	A()
	{
		++_count;
	}
	A(const A& t)
	{
		++_count;
	}
	static int Getcount()//static���γ�Ա����
	{
		return _count;
	}
private:
	static int _count;//static���γ�Ա����
};
int A::_count = 0;
void Test()
{
	cout << A::Getcount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::Getcount() << endl;

}
#endif
#if 0 
//��Ԫ����
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
 ostream& operator<<(ostream& _cout, const Date& d)

{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int main()
{
	Date d(2019,7,29);
	cout << d;
	return 0;
}
#end if
#if 0
class A
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	A()
		: _a(a)
	{}
private:
	int _a;
};
class B
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	B()
		:_b(b)
	{}
private:
	int _b;
};
ostream& operator<<(ostream& _cout, const Date& d)

{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int main()
{
	A a;
	cout << a;
	B b;
	cout << b;
	return 0;
}
#endif

#if 0
//��Ԫ��
class Date;//ǰ������
class Time
{
	frend class Date;//������������ʵ�������Ԫ��
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 2019,int month = 7,int day = 29)
		:_year(year)
		, _month(month)
		_day(day)
	{}
	void Settimeofdate(int hour, int minute, int second)
	{
		//ֱ�ӷ���Time���е�˽�г�Ա
		_t._hour = hour;
		_t._minute = minute;
		_t._second - second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
#endif

//�ڲ���

class A
{
public:
	class B
	{
	public:
		void print(const A& a)
		{
			cout << t << endl;
			cout << a.c << endl;
		}
	};
private:
	static int t;
	int c;
};
int A::t = 1;
int main()
{
	A::B b;
	b.print(A());
	return 0;
}