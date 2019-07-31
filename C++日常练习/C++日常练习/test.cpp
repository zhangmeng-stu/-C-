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

#if 0
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
#endif


#if 0
//列表初始化
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
	int& _d;//引用
	Time _hour;//没用默认构造函数
};
#endif

#if 0
//计算程序中创建出多少类对象
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
	static int Getcount()//static修饰成员函数
	{
		return _count;
	}
private:
	static int _count;//static修饰成员变量
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
//友元函数
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
//友元类
class Date;//前置声明
class Time
{
	frend class Date;//声明日期类是实践类的友元类
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
		//直接访问Time类中的私有成员
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
#if 0
//内部类

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
#endif
#if 0
//内存分布
int globalVar = 1;//全局变量
static int staticGlobalVar = 1;//静态全局变量
int main()
{
	static int staticVat = 1;//静态局部变量
	int localVar = 1;//局部变量

	int num1[10] = { 1, 2, 3, 4, 5, 6 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);

}

void test()
{
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	free(ptr1);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr3);
}
#endif
#if 0
//new delete
int main()
{
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[4];

	delete() p1;
	delete() p2;
	delete[] p3;
	return 0;
}
#endif
class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test()" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
	private:
	int _data;
};
void test1()
{
	//申请单个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	//申请4个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test)* 4);
	free(p2);
}
void test2()
{
	//申请单个Test类型的空间
	int* p3 = new int;
	delete() p3;
	//申请4个Test类型的空间
	int* p4 = new int[4];
	delete[] p4;
}

	/* operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；
	申请空间失败，尝试执行空间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。 */
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc) 
{    // try to allocate size bytes   
	void *p;    
	while ((p = malloc(size)) == 0)        
	if (_callnewh(size) == 0)      
	{           
		// report no memory           
		// 如果申请内存失败了，这里会抛出bad_alloc 类型异常           
		static const std::bad_alloc nomem;            
		_RAISE(nomem);       
	}

		return (p);
	}

/* operator delete: 该函数最终是通过free来释放空间的 */\
void operator delete(void *pUserData)
{
	_CrtMemBlockHeader * pHead;

	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));

	if (pUserData == NULL) 

		return;

	_mlock(_HEAP_LOCK);  /* block other threads */        
	__TRY
    /* get a pointer to memory block header */           
	pHead = pHdr(pUserData);

	/* verify block type */           
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));

	_free_dbg(pUserData, pHead->nBlockUse);

	__FINALLY            
		_munlock(_HEAP_LOCK);  /* release other threads */       
	__END_TRY_FINALLY

		return;
}
#endif
#if 0
void* operator new(size_t n)
{
	void* p = nullptr;
	p = allocator<ListNode>().allocate(1);
	p = allocator<ListNode>().allocate(1);
	cout << "memory pool allocate" << endl;
	return p;
}
 
void operator delete(void* p)
{
	allocator<ListNode>().deallocate((listNode*)p, 1);
	cout << "memory pool deallocate" << endl;
}
#endif

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>
int main()
{
	int* p1 = new int[10];

	_CrtDumpMemoryLeaks();
	return 0;
}