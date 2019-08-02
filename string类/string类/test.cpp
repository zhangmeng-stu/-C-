#include <iostream>
using namespace std;
#include <string>

void test1()
{
	string s1;                 //构造空的string类对象s1
	string s2("hello world"); //用C格式字符串构造string类对象s2
	string s3(s2);           //拷贝构造s3
}

void test2()
{
	//string s("hello world");
	//cout << s.size() << endl;
	//cout << s.length() << endl;
	//cout << s.capacity() << endl;

	////将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小 
	//s.clear();
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的字符增加到10个，多出来的位置用'!'进行填充
	s.resize(10, '!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的字符增加到20个，多处的位置用‘c’进行填充
	s.resize(20, 'c');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的字符缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void test3()
{
	string s;
	//在VS编译器下原有的容量
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将容量扩大到10
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将容量扩大到30
	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将容量缩小到20
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将容量缩小到10
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test4()
{
	string s1("hello world");
	const string s2("Hello world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;
}

void test5()
{
	//三种遍历方式
	string s("Hello wrold");
	//1.for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] ;
	}

	//2.范围for循环
	for (auto ch : s)
	{
		cout << ch << endl;
	}

	//3.迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
	}
}
void test6()
{
	string s("hello");
	s.push_back(' ');   //在s后插入空格
	s.append("world");  //在s后追加一个字符"world"
	s += 'h';           // 在str后追加一个字符'h'       
	s += "it";          // 在str后追加一个字符串"it"    
	cout << s << endl;
	cout << s.c_str() << endl; //以C语言的方式打印字符串

	//获取file的后缀
	string file("exe.cpp");
	string  pos =file.substr( file.rfind('.'),file.size()-file.rfind('.'));
	cout << pos << endl;
}




void TestString() {
	string str;
	str.push_back(' ');   // 在str后插入空格    
	str.append("hello");  // 在str后追加一个字符"hello"   
	str += 'b';           // 在str后追加一个字符'b'       
	str += "it";          // 在str后追加一个字符串"it"    
	cout << str << endl;
	cout << str.c_str() << endl;   // 以C语言的方式打印字符串        
	
	// 获取file的后缀   
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));//截取字符串
	cout << suffix << endl;
}
int main()
{
	test6();
	return 0;
}