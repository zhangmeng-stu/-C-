#include <iostream>
using namespace std;

#if 0
异常的抛出
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
//异常的重新抛出
double Division(int a, int b)
{
	//当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	/*如果这里发生了除0错误抛出异常，另外下面的array没有得到释放。
	所以这里捕获的异常后并不处理。异常还是交给外面处理，这里捕获
	了再重新抛出*/
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

//这里表示这个函数抛出A/B/C/D中的某种类型的异常
void fun()throw(A, B, C, D);
//这里表示这个函数只会抛出bad_alloc的异常
void* operator new(std::size_t size)throw(std::bad_alloc);
//这里表示这个函数不会抛出异常
void* operator new(std::size_t size, void* ptr)throw();
