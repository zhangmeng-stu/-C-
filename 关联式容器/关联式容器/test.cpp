#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <set>

#if 0
void testmap()
{
	map<string, string> m;

	//��map�в���Ԫ��
	//������ֱ���������ֵ��
	m.insert(pair<string, string>("apple", "ƻ��"));
	//��make_pair�����������ֵ��
	m.insert(make_pair("peach", "����"));
	//����operator[]
	/*    operator[]��ԭ���ǣ�    
	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��  
	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����   
	operator[]������insert����ֵ��ֵ���е�value����    */
	m["watermelon"] = "����";
	cout << m.size() << endl;

	for (auto& e : m)
	{
		cout << e.first << "<--->" << e.second << endl;
	}

	//map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
	auto ret = m.insert(make_pair("peach", "t��ɫ"));
	if (ret.second)
		cout << "�Ѳ���" << endl;
	else
		cout << "����ʧ��" << endl;

	//ɾ��key
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "ɾ��ʧ��" << endl;
	else
		cout << "ɾ���ɹ�" << endl;
}



//����key����
void testmap()
{
	map<int, int> m;
	int array[] = { 4, 2, 6, 8, 9, 7, 1, 3, 5, 0 };
	for (size_t i = 0; i < 10; i++)
		m.insert(make_pair(array[i], i));

	for (auto e : m)
		cout << e.first << "<---->" << e.second << endl;
}
#endif

#if 0
#include <set>
void testset()
{
	int array[] = { 5, 1, 4, 6, 7, 9, 5, 2, 3, 4, 8, 9, 3, 4, 2, 6, 7, 9, 8, 1 };
	set<int>s;
	for (auto e : array)
		s.insert(e);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//set��ֵΪ5��Ԫ�س����˼���
	cout << s.count(5) << endl;
}

#endif

void testset()
{
	int array[] = { 2, 1, 3, 5, 6, 4, 9, 6, 5, 2 };
	//multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ�� 
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : s)
		cout << e << " ";
	cout <<endl;
}
int main()
{
	//testmap();
	testset();
	return 0;
}