#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#if 0 
//1.最难的问题（字符串）
int main()
{
	string s;
	while (getline(cin, s))
	{
		string temp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A'&&s[i] <= 'E')
				temp += s[i] + 21;
			else if (s[i] >= 'F' && s[i] <= 'Z')
				temp += s[i] - 5;
			else
				temp += s[i];
		}
		cout << temp << endl;
	}
	return 0;
}
#endif

//因子个数

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
				count++;
			while (n%i == 0)
				n /= i;
		}
		if (n != 1)
			count++;
		cout << count << endl;
	}
	return 0;
}