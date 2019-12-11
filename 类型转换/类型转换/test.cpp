#include <iostream>
using namespace std;

#if 0
int main()
{
	int i = 1;
	//隐式类型转换
	double d = i;
	printf("%d, %.2f\n", i, d);

	int *p = &i;
	//显示的强制类型转换
	int address = (int)p;
	printf("%x,%d\n", p, address);

}
#endif

#if 0
//reinterpret_cast
typedef void(*FUNC)();
int Dosomething(int i)
{
	cout << "Dosomething" << endl;
	return 0;
}
void Test()
{
	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
	//
	FUNC f = reinterpret_cast<FUNC>(Dosomething);
	f();
} 


//static_cast
int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;

	int *pa = &a;
	pa = reinterpret_cast<int*>(&d);
	

	return 0;
}

// const int*
int main()
{
	const int c = 10;
	int* pc = const_cast<int*>(&c); 
	*pc = 1;

	return 0;
}
#endif

#if 0
//dynamic_cast
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}
private:
	int _b;
};
class Derived :public Base
{
public:
	void funcD()
	{
		cout << "Deriverd::funcD()" << endl;
	}
private:
	int _d;
};

void func(Base* pa)
{
	pa->func();//实现多态
	// 如果pa指向的是子类对象，可能需要借助子类的成员函数做一些其他事情
	Derived* pb1 = dynamic_cast<Derived*>(pa);
	Derived* pb2 = static_cast<Derived*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;

	if (pb1)
		pb1->funcD();
	if (pb2)
		pb2->funcD();
}

int main()
{
	Base b;
	Derived d;
	//赋值兼容规则
	b = d;
	Base*pb = &d;
	Base& rb = d;
	Derived* pd = dynamic_cast<Derived*>(&b);

	func(&b);
	func(&d);

	return 0;
}
#endif

//explicit
class Date
{
public:
	explicit Date(int year, int month = 1, int day = 1)
		:_year(year)
		, _month(1)
		, _day(1)
	{
		cout << "Date::Data(int):" << this << endl;
	}
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
	~Date()
	{
		cout << "Date::~Data(int):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019);
	//隐式转换，发生错误
	//d1 = 2020;
	return 0;
}