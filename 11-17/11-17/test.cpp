#include <iostream>
using namespace std;

#if 0
//1.��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b��
//�����һ���㷨�����a��b�������������ȵı�š�
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


//2.��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
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