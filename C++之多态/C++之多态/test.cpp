#include <iostream>
using namespace std;

//�麯����д
#if 0
class Person
{
public:
	virtual void Buyticket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student :public Person
{
public:
	virtual void Buyticket()
	{
		cout << "��Ʊ-���" << endl;
	}
	/*ע�⣺����д���ຯ��ʱ����������麯���ڲ���virtual�ؼ���ʱ��
	��ȻҲ���Թ�����д����Ϊ�ڼ̳к������麯�����̳к���������
	�ڼ̳к������麯�����̳������������������ɱ����麯������
	���Ǹ���д�����Ǻܹ淶������������ʹ��*/
	/*virtual void Buyticket()
	{
		cout << "��Ʊ-���" << endl;
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


//Э��
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

//������������д
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
/*ֻ����������Student������������д��Person������������
�����delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�����������*/
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
		cout << "����" << endl;
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
		cout << "ʹ��" << endl;
	}
};
#endif

#if 0
//������
class Car
{
public:
	virtual void Drive() = 0;//������
};

class B : public Car
{
	virtual void Drive()
	{
		cout << "B-ʹ��" << endl;
	}
};
class C :public Car
{
	virtual void Drive()
	{
		cout << "C-����" << endl;
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
//�麯����
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