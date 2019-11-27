#include <iostream>
#include <string>
using namespace std;

#if 0
/*1.��ˮƿ
�ݹ�����
3��ƿ�ӻ�1ƿˮ+1����ƿ�ӣ�����ƿ�ӻ�1ƿˮ+0����ƿ�ӣ�1��ƿ�ӻ�0ƿˮ��
f(1) = 0
f(2) = 1
f(3) = 1
f(4) = f(2)+1    //4��ƿ�ӣ�����3�����Ի�1ƿˮ+1����ƿ��������f(2)+1
f(5) = f(3)+1    //3��ƿ�ӻ�1ƿˮ+1����ƿ��������f(3)+1
...
f(n) = f(n-2)+1 */
int f(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	return f(n - 2) + 1;
}

int main()
{
	int n;
	while (cin >> n){
		if (n == 0)
			break;
		cout << f(n) << endl;
	}
	return 0;
}
#endif

//2.
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() < b.size())
			swap(a, b);
		string str;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp)) < 0)
					break;
				else if (str.size() < temp.size())
					str = temp;
			}
		}
		cout << str << endl;
	}
	return 0;
}