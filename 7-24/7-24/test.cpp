#include <iostream>
using namespace std;
#include <string.h>
#if 0
//�����ռ�
//1.��ͨ�������ռ�
namespace N1 // N1Ϊ�����ռ������ 
{   // �����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��  
	int a;  
	int Add(int left, int right)  
	{     
		return left + right;   
	}
}
//2.�����ռ����Ƕ��
namespace N2
{
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int b;
	}
	int Add(int left, int right)
	{
		return left + right;
	}
}

//��������
#include <iostream>
using namespace std;
int main()
{
	cin >> "a";
	cout << "hello world!!!" << endl;
	return 0;
}
/*
//ȱʡ����

void test(int a = 1,int b =2)
{
	cout << a <<" "<< b << endl;
}
int main()
{
	test();//û�д��Σ���ʹ��ȱʡ����
	test(3, 4);
	return 0;
}
*/
//ȫȱʡ����
void test(int a = 1; int b = 2; int c = 3;)
{
	cout << a << " " << b << " " << c << endl;
}
//��ȱʡ����
void test(int a; int b = 2; int c = 3;)
{
	cout << a << " " << b << " " << c << endl;
}

//��������
int Add(int left, int right)
{
	return left + right;
}
   extren "C"double Add(double left, double right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
}

//����
void TestRef() {
	int a = 10;  
	int& ra = a;//<====������������       
	printf("%p\n", &a);  
	printf("%p\n", &ra);
}

void Test()
{
	const int a = 10;
	 //int &a = 20; ���������Ըı�a��ֵ
	const int &ra = a;
}

//������
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//��Ϊ����ֵ
int &add(int &a, int &b)
{
	return a + b;
}
int main()
{
	int &t = add(1, 2);
	add(3, 4);
}
//��������
inline int add(int a, int b)
{
	return a + b;
}
int main()
{
	int t = add(1, 2);
	add(3, 4);
}
//auto
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = Add(1, 2);

	cout << typeid(b).name() << endl;  //typeid���������
	cout << typeid(c).name() << endl;  
	cout << typeid(d).name() << endl;

}

int main()
{
	int a = 10;
	auto b = 2, c = 3;
	auto d = 1.2,e =3;//��������ԣ��������Ͳ�ͬ
}

#endif
#if 0
//forѭ��
void test()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i] = array[i] * 2;
	}
	for (int * p = array; p < array + sizeof(array) / sizeof(array[0]); p++)
		cout << *p << endl;
}

void TestFor() 
{ 
	int array[] = { 1, 2, 3, 4, 5 };    
	for (auto& e : array)
	{
		e *= 2;
	}   
	for (auto e : array)
	{
		cout << e << " ";
	}
	return 0;
}

void Test()
{
	int *p = NULL;
	int *p = 0;
}

#endif
#if 0
//��c�����нṹ��Ķ���
struct Node
{
	int val;
	Node* left;
	Node* right;
};

//��C++�нṹ�������
class Student
{
public:
	void SetStudent(char *name, char *gander, int age)
	{
		strcpy(_name, name);
		strcpy(_gander, gander);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << " " << _gander << " " << _age << endl;
	}
private:
	char _name[20];
	char _gander[3];
	int _age;
};


//���������
class student{
public:
	void printstudent();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

void student::printstudent()
{
	cout << _name << " " << _genger << "" << _age << endl;
}

#end if
#if 0
//���ʵ����
class student{
public:
	void Setstudent(char *name, char *gander, int age)
	{
		strcpy(_name, name);
		strcpy(_gander, gander);
		_age = age;
	}
	void printstudent()
	{
		cout << _name << " " << _genger << "" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	student s;
	s.Setstudent("haha", "��", "18");
	s.printstudent;

}
#endif

class Date
{
public:
	void SetDate(int year, int month, int second)
	{
		_year = year;
		_month = month;
		_second = second;
	}
	void PrintDate()
	{
		cout << _year << " " << _month << " " << _second << endl;
	}
private:
	int _year;
	int _month:
	int _second;
};

int main()
{
	Date d;
	d.SetDate(2019 7 24);
	d.PrintDate;
}