#include <iostream>
using namespace std;

/*
客似云来*/

int cook(int i)
{
	if (i == 1 || i == 2)
	{
		return 1;
	}
	else
		return cook(i - 1) + cook(i - 2);
}
int main()
{
	int n, m;
	int t = 0;
	cin >> m >> n;
	for (int i = n; i<m + 1; i++)
	{
		t += cook(i);
	}

	cout << t;
	return 0;
}

/*
剪花布条*/