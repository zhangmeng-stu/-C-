#include <iostream>
using namespace std;

#if 0
�쳣���׳�
double Division(int a, int b)
{
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unknow exception" << endl;
		return 0;
	}
}

#endif

#if 0
//�쳣�������׳�
double Division(int a, int b)
{
	//��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	/*������﷢���˳�0�����׳��쳣�����������arrayû�еõ��ͷš�
	�������ﲶ����쳣�󲢲������쳣���ǽ������洦�����ﲶ��
	���������׳�*/
	int *array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete[]" << array << endl;
		delete[] array;
		throw;
	}
	cout << "delete[]" << array << endl;
	delete[] array;
}
int main()
{
	try{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unknow exception" << endl;
		return 0;
	}
}

#endif

//�����ʾ��������׳�A/B/C/D�е�ĳ�����͵��쳣
void fun()throw(A, B, C, D);
//�����ʾ�������ֻ���׳�bad_alloc���쳣
void* operator new(std::size_t size)throw(std::bad_alloc);
//�����ʾ������������׳��쳣
void* operator new(std::size_t size, void* ptr)throw();
