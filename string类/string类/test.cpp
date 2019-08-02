#include <iostream>
using namespace std;
#include <string>

void test1()
{
	string s1;                 //����յ�string�����s1
	string s2("hello world"); //��C��ʽ�ַ�������string�����s2
	string s3(s2);           //��������s3
}

void test2()
{
	//string s("hello world");
	//cout << s.size() << endl;
	//cout << s.length() << endl;
	//cout << s.capacity() << endl;

	////��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С 
	//s.clear();
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е��ַ����ӵ�10�����������λ����'!'�������
	s.resize(10, '!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е��ַ����ӵ�20�����ദ��λ���á�c���������
	s.resize(20, 'c');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е��ַ���С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void test3()
{
	string s;
	//��VS��������ԭ�е�����
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//����������10
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//����������30
	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//��������С��20
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//��������С��10
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
	//���ֱ�����ʽ
	string s("Hello wrold");
	//1.for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] ;
	}

	//2.��Χforѭ��
	for (auto ch : s)
	{
		cout << ch << endl;
	}

	//3.������
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
	s.push_back(' ');   //��s�����ո�
	s.append("world");  //��s��׷��һ���ַ�"world"
	s += 'h';           // ��str��׷��һ���ַ�'h'       
	s += "it";          // ��str��׷��һ���ַ���"it"    
	cout << s << endl;
	cout << s.c_str() << endl; //��C���Եķ�ʽ��ӡ�ַ���

	//��ȡfile�ĺ�׺
	string file("exe.cpp");
	string  pos =file.substr( file.rfind('.'),file.size()-file.rfind('.'));
	cout << pos << endl;
}




void TestString() {
	string str;
	str.push_back(' ');   // ��str�����ո�    
	str.append("hello");  // ��str��׷��һ���ַ�"hello"   
	str += 'b';           // ��str��׷��һ���ַ�'b'       
	str += "it";          // ��str��׷��һ���ַ���"it"    
	cout << str << endl;
	cout << str.c_str() << endl;   // ��C���Եķ�ʽ��ӡ�ַ���        
	
	// ��ȡfile�ĺ�׺   
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));//��ȡ�ַ���
	cout << suffix << endl;
}
int main()
{
	test6();
	return 0;
}