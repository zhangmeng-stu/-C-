#include <iostream>
using namespace std;


#if 0
//基类
class Person
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "Mary";
	int _age = 21;
};

class Student :public Person
{
protected:
	int _stuid;//学号
};
#endif


#if 0
//赋值转换
class Person
{
protected:
	string _name;//姓名
	string _sex;//性别
	string _age;//年龄
};
class Student : public Person
{
public:
	int _number;//学号
};
int main()
{
	Student s;
	//子类对象可以直接赋值给父类对象
	Person p = s;
	//基类指针或者引用直接指向子类的对象
	Person* pp = &s;
	Person& rp = s;

	//基类对象不能赋值给派生类对象
	s = p;

	//基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &s;
	Student* ps = (Student*)pp;//这种状况转换是可以的；
	ps->_number = 1;

	pp = &p;
	Student* ps1 = (Student*)pp;//这种状况转换虽然可以的，但是存在越界访问的问题
	ps1->_number = 1;
}

//同名隐藏

//Base中的_num和Derived中的_num构成隐藏关系

//Base中的print和Derived中的print构成隐藏，成员函数满足函数名相同就构成隐藏
class  Base
{
public:
	void print()
	{
		cout << "hello" << endl;
	}
protected:
	int _num = 112;
};
class Derived : public Base
{
public:
	void print()
	{
		Base::print();
		cout << "world" << endl;
	}
protected:
	int _num = 110;
};

void test()
{
	Base b;
	b.print();
}


//默认的成员函数

//基类
class Base
{
public:
	//构造函数
	Base(const int b = 1)
		:_b(b)
	{
		cout << "Base()" << endl;
	}
	//拷贝构造函数
	Base(const Base& b)
		:_b(b._b)
	{
			cout << "Base(const Base& b)" << endl;
		}
	//运算符重载
	Base& operator=(const Base& b)
	{
		cout << "Base& operator=(const Base& b)" << endl;
		if (this != &b)
		{
			_b = b._b;
		}
		return *this;
	}
	//析构函数
	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _b;
};
//派生类
class Derived : public Base
{
public:
	//构造函数
	Derived(const int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived()" << endl;
	}
	//拷贝构造函数
	Derived(const Derived& d)
		:Base(d)
		, _d(d._d)
	{
		cout << "Derived(const Derived& d)" << endl;
	}
	//运算符重载
	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}
	//析构函数
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
protected:
	int _d;
};

int main()
{
	Derived d1(1,2);
	Derived d2(d1);
	Derived d3(3,4);
	d1 = d3;
	return 0;
}


//友元关系
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student);
protected:
	string _name;
};
class Student : public Person
{
protected:
	int _stNum;
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stNum << endl;
}


//静态成员
class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name;
public:
	static int _count;//统计人的个数
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stNum;//学号
};
class  Graduate : public Student
{
protected:
	string _seminarCourse;//研究项目
};
void Test()
{
	Student s1; 
	Student s2;
	Student s3;
    Graduate s4;
	cout << " 人数 :" << Person::_count << endl;   
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}
#endif

//菱形继承
class Person
{
public :
	string _name;
};
class Student : virtual public Person
{
protected:
	int _num;
};
class Teacher : virtual public Person
{
protected:
	int _id;//身份证号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};

int main()
{
	Assistant  a;
	a._name = "Lily";
}