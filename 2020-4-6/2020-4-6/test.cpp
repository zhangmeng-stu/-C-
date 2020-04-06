#include <iostream>
using namespace std;
/*数据库连接池

Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。
为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，
系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。

输入：包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。

紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。
*/

#include <string>
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, max_count = 0;
		string id, method;
		while (n--)
		{
			cin >> id >> method;
			if (method == "connect")
				count++;
			if (method == "disconnect")
				count--;
			if (count > max_count)
				max_count = count;
		}
		cout << max_count << endl;
	}
	return 0;
}

/*mkdir
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，
就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，
只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。
输入：每组数据第一行为一个正整数n(1≤n≤1024)。
紧接着n行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过200个字符。
*/

#include <vector>

#include <fstream>
#include <algorithm>

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end());

		for (int i = 0; i < list.size() - 1; ++i)
		{
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
				flag[i] = false;
		}

		for (int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}