#include <iostream>
using namespace std;


#if 0
//����
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
	int _stuid;//ѧ��
};
#endif


#if 0
//��ֵת��
class Person
{
protected:
	string _name;//����
	string _sex;//�Ա�
	string _age;//����
};
class Student : public Person
{
public:
	int _number;//ѧ��
};
int main()
{
	Student s;
	//����������ֱ�Ӹ�ֵ���������
	Person p = s;
	//����ָ���������ֱ��ָ������Ķ���
	Person* pp = &s;
	Person& rp = s;

	//��������ܸ�ֵ�����������
	s = p;

	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &s;
	Student* ps = (Student*)pp;//����״��ת���ǿ��Եģ�
	ps->_number = 1;

	pp = &p;
	Student* ps1 = (Student*)pp;//����״��ת����Ȼ���Եģ����Ǵ���Խ����ʵ�����
	ps1->_number = 1;
}

//ͬ������

//Base�е�_num��Derived�е�_num�������ع�ϵ

//Base�е�print��Derived�е�print�������أ���Ա�������㺯������ͬ�͹�������
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


//Ĭ�ϵĳ�Ա����

//����
class Base
{
public:
	//���캯��
	Base(const int b = 1)
		:_b(b)
	{
		cout << "Base()" << endl;
	}
	//�������캯��
	Base(const Base& b)
		:_b(b._b)
	{
			cout << "Base(const Base& b)" << endl;
		}
	//���������
	Base& operator=(const Base& b)
	{
		cout << "Base& operator=(const Base& b)" << endl;
		if (this != &b)
		{
			_b = b._b;
		}
		return *this;
	}
	//��������
	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _b;
};
//������
class Derived : public Base
{
public:
	//���캯��
	Derived(const int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived()" << endl;
	}
	//�������캯��
	Derived(const Derived& d)
		:Base(d)
		, _d(d._d)
	{
		cout << "Derived(const Derived& d)" << endl;
	}
	//���������
	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}
	//��������
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


//��Ԫ��ϵ
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


//��̬��Ա
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
	static int _count;//ͳ���˵ĸ���
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stNum;//ѧ��
};
class  Graduate : public Student
{
protected:
	string _seminarCourse;//�о���Ŀ
};
void Test()
{
	Student s1; 
	Student s2;
	Student s3;
    Graduate s4;
	cout << " ���� :" << Person::_count << endl;   
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}
#endif

//���μ̳�
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
	int _id;//���֤��
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