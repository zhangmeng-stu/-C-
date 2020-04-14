#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
对字符串中的所有单词进行倒排。
*/
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a'&&str[i] <= 'z' || str[i] >= 'A'&&str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size()>0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size() > 0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i > 0; i--)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;

	}
	return 0;
}



/*
骆驼命名法
*/
int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();
		string::iterator it = s.begin();
		while (it != s.end())
		{
			if (*it == '_')
			{
				it = s.erase(it);
				*it -= 32;
			}
			else
				it++;
		}
		cout << s << endl;
	}
	return 0;
}
