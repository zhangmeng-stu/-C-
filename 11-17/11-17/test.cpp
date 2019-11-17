#include <iostream>
using namespace std;

#if 0
//1.有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。
//请设计一个算法，求出a和b点的最近公共祖先的编号。
class LCA
{
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};
#endif


//2.求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
int main()
{
	int byte;
	while (cin >> byte)
	{
		int max = 0;
		int count = 0;
		while (byte)
		{
			
			while (byte && (byte & 1))
			{
				byte = byte >> 1;
				count++;
			}
			if (!(byte & 1))
			{
				if (count > max)
					max = count;
				count = 0;
				byte = byte >> 1;
			}
		}
		cout << max << endl;
	}
	return 0;
}