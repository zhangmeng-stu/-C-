#include <iostream>
using namespace std;

//虚函数重写
#if 0
class Person
{
public:
	virtual void Buyticket()
	{
		cout << "买票-全价" << endl;
	}
};
class Student :public Person
{
public:
	virtual void Buyticket()
	{
		cout << "买票-半价" << endl;
	}
	/*注意：在重写基类函数时，派生类的虚函数在不加virtual关键字时，
	虽然也可以构成重写（因为在继承后基类的虚函数被继承函数下来了
	在继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性
	但是该种写法不是很规范，不建议这样使用*/
	/*virtual void Buyticket()
	{
		cout << "买票-半价" << endl;
	}*/
};
void Func(Person& p)
{
	p.Buyticket();
}
int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}


//协变
class A{};
class B : public A{};
class Person{
public:
	virtual A* f()
	{
		return new A;
	}
};
class Student : public Person{
public:
	virtual B* f()
	{
		return new B;
	}
};
#endif

//析构函数的重写
#if 0
class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
};

class Student :public Person
{
public:
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
};
/*只有在派生类Student的析构函数重写了Person的析构函数，
下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数*/
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;

	delete p1;
	delete p2;
	return 0;
 }

//final
class A
{ 
public:
	virtual void  Drive()final{}
};
class B :public A
{
public:
	virtual void Drive()
	{
		cout << "辛苦" << endl;
	}
};

//override
class A{
public:
	virtual void Drive(){}
};
class B :public A
{
public:
	virtual void Drive()override
	{
		cout << "痛苦" << endl;
	}
};
#endif

#if 0
//抽象类
class Car
{
public:
	virtual void Drive() = 0;//抽象类
};

class B : public Car
{
	virtual void Drive()
	{
		cout << "B-痛苦" << endl;
	}
};
class C :public Car
{
	virtual void Drive()
	{
		cout << "C-舒适" << endl;
	}
};
void Test()
{
	Car* pB = new B;
	pB->Drive();

	Car* pC = new C;
	pC->Drive();
}
#endif

#if 0
//虚函数表
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1" << endl;
	}
private:
	int _b = 1;
};


int main()
{
	Base b;

	return 0;
}

#endif

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2" << endl;
	}
    void Func3()
	{
		cout << "Base::Func3" << endl;
	}
private:
	int _b = 1;
};
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;

	return 0;
}