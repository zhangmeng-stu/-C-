#include <iostream>
using namespace std;
#include <string.h>
#if 0
//命名空间
//1.普通的命名空间
namespace N1 // N1为命名空间的名称 
{   // 命名空间中的内容，既可以定义变量，也可以定义函数  
	int a;  
	int Add(int left, int right)  
	{     
		return left + right;   
	}
}
//2.命名空间可以嵌套
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

//输入和输出
#include <iostream>
using namespace std;
int main()
{
	cin >> "a";
	cout << "hello world!!!" << endl;
	return 0;
}
/*
//缺省参数

void test(int a = 1,int b =2)
{
	cout << a <<" "<< b << endl;
}
int main()
{
	test();//没有传参，就使用缺省参数
	test(3, 4);
	return 0;
}
*/
//全缺省参数
void test(int a = 1; int b = 2; int c = 3;)
{
	cout << a << " " << b << " " << c << endl;
}
//半缺省参数
void test(int a; int b = 2; int c = 3;)
{
	cout << a << " " << b << " " << c << endl;
}

//函数重载
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

//引用
void TestRef() {
	int a = 10;  
	int& ra = a;//<====定义引用类型       
	printf("%p\n", &a);  
	printf("%p\n", &ra);
}

void Test()
{
	const int a = 10;
	 //int &a = 20; 这样不可以改变a的值
	const int &ra = a;
}

//做参数
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//作为返回值
int &add(int &a, int &b)
{
	return a + b;
}
int main()
{
	int &t = add(1, 2);
	add(3, 4);
}
//内联函数
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

	cout << typeid(b).name() << endl;  //typeid求变量类型
	cout << typeid(c).name() << endl;  
	cout << typeid(d).name() << endl;

}

int main()
{
	int a = 10;
	auto b = 2, c = 3;
	auto d = 1.2,e =3;//这个不可以，变量类型不同
}

#endif
#if 0
//for循环
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
//在c语言中结构体的定义
struct Node
{
	int val;
	Node* left;
	Node* right;
};

//在C++中结构体的作用
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


//类的作用域
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
//类的实例化
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
	s.Setstudent("haha", "男", "18");
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