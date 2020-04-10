#include <iostream>
using namespace std;
#include <string>

/*
五子棋（20*20）
*/
bool Isfive(string v[])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (v[i][j] == '.')
				continue;
			int right = 1, down = 1, right_down = 1, left_down = 1;
			for (int t = 1; t < 5; t++)
			{
				if (j<16 && v[i][j] == v[i][j + t])
						right++;
				if (i<16 && v[i][j] == v[i + t][j])
					down++;
				if (j<16 && i<16 && v[i][j] == v[i + t][j + t])
					right_down++;
				if (j>3 && i<16 && v[i][j] == v[i + t][j - t])
					left_down++;
			}
			if (right == 5 || down == 5 || right_down == 5 || left_down == 5)
				return true;
		}
	}
	return false;
}
int main()
{
	string s[20];
	while (cin >> s[0])
	{
		for (int i = 1; i < 20; i++)
			cin >> s[i];
		cout << (Isfive(s) ? "Yes" : "No") << endl;
	}
	return 0;
}

/*
emacs计算器
后缀表达式的计算器，运算符在操作数后面
*/

#include <stack>

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		stack<int> st;
		for (size_t i = 0; i<n; i++)
		{
			int sum = 0;
			string ch;//运用string而不是用char的原因是，char只能存10以下的字符，当输入的字符
			//大于10，就会出现错误
			cin >> ch;
			if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')
			{
				int right = st.top();//栈结构，自底向上，所以取值时，需要先取右操作数
				st.pop();
				int left = st.top();
				st.pop();
				if (ch[0] == '+')
					sum = left + right;
				if (ch[0] == '-')
					sum = left - right;
				if (ch[0] == '*')
					sum = left*right;
				if (ch[0] == '/')
				{
					if (right != 0)
						sum = left / right;
					else
						return 0;
				}
				st.push(sum);
			}
			else
				st.push(atoi(ch.c_str()));
		}
		cout << (int)st.top() << endl;
	}
	return 0;
}

