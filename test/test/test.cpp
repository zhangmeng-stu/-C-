#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};
class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person Mike;
	Func(Mike);

	Student John;
	Func(John);
	return 0;
}
#endif


//单继承中的虚函数表
class Base
{
public:
	virtual void func1()
	{
		  cout << "Base::func1" << endl;
	}
	virtual void func2()
	{
		  cout << "Base::func2" << endl;
	}
private:
	int a;
};

class Derive : public Base
{
public:
	virtual void func1()
	{
		cout << "Derive::func1" << endl;
	}
	virtual void func3()
	{
		cout << "Derive::func3" << endl;
	}
	virtual void func4()
	{
		cout << "Derive::func4" << endl;
	}
private:
	int b;
};

typedef void(*VFPTR)();
void PrintVTable(VFPTR vTable[])
{
	//依次取虚函数指针打印并调用，
	cout << "虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址：0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);

	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}



#if 0
//多继承中的虚函数表
class Base1 { 
public:    
	virtual void func1() 
	{ 
		cout << "Base1::func1" << endl;
	}    
	virtual void func2() 
	{ 
		cout << "Base1::func2" << endl;
	} 
private:    
	int b1; 
};

class Base2 
{ public:    
	virtual void func1() 
	{
		cout << "Base2::func1" << endl;
	}   
	virtual void func2() 
	{ 
		cout << "Base2::func2" << endl; 
	} 
private:    
	int b2; 
};

class Derive : public Base1, public Base2 
{ 
public:    
	virtual void func1() 
	{ 
		cout << "Derive::func1" << endl; 
	}    
	virtual void func3() 
	{ 
		cout << "Derive::func3" << endl; 
	} private:    
		int d1; 
};

typedef void(*VFPTR) (); 
void PrintVTable(VFPTR vTable[]) 
{ 
	cout << " 虚表地址>" << vTable << endl;   
	for (int i = 0; vTable[i] != nullptr; ++i)    
	{ 
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);      
		VFPTR f = vTable[i];      
		f(); 
	}    
	cout << endl;
}

int main() {
	Derive d;

	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);   
	PrintVTable(vTableb1);

	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1))); 
	PrintVTable(vTableb2);

	return 0;
}

#endif