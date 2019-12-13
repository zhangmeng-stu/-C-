#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <set>

#if 0
void testmap()
{
	map<string, string> m;

	//向map中插入元素
	//用派人直接来构造键值对
	m.insert(pair<string, string>("apple", "苹果"));
	//用make_pair函数来构造键值对
	m.insert(make_pair("peach", "桃子"));
	//借用operator[]
	/*    operator[]的原理是：    
	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中  
	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器   
	operator[]函数后将insert返回值键值对中的value返回    */
	m["watermelon"] = "西瓜";
	cout << m.size() << endl;

	for (auto& e : m)
	{
		cout << e.first << "<--->" << e.second << endl;
	}

	//map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach", "t桃色"));
	if (ret.second)
		cout << "已插入" << endl;
	else
		cout << "插入失败" << endl;

	//删除key
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "删除失败" << endl;
	else
		cout << "删除成功" << endl;
}



//关于key有序
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

	//set中值为5的元素出现了几次
	cout << s.count(5) << endl;
}

#endif

void testset()
{
	int array[] = { 2, 1, 3, 5, 6, 4, 9, 6, 5, 2 };
	//multiset在底层实际存储的是<int, int>的键值对 
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