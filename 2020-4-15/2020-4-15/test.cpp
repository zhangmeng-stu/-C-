#include <iostream>
#include <string>
using namespace std;
#include <algorithm>



void judge(string&s1, string& s2)
{
	int len1 = 1, len2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	size_t i = 0;
	while (i < s2.size())
	{
		if (s1.find(s2[i]) == string::npos)
		{
			cout << "No" << endl;
			return;
		}

			len1 = (s1.rfind(s2[i]) - s1.find(s2[i]) + 1);
			len2 = (s2.rfind(s2[i]) - s2.find(s2[i]) + 1);
			if (len1 < len2)
			{
				cout << "No" << endl;
				return;
			}
			i++;
		 
		}
		cout << "Yes" << endl;
}
int main()
{
	string s1, s2;
	while (cin >> s1)
	{
		cin >> s2;
		judge(s1, s2);
	}
}