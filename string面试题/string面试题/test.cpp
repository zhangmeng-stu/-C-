//字符串的最后一个单词长度
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
	return 0;
}