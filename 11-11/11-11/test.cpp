#include <iostream>
#include <string>
using namespace std;


#if 0
//1.��������
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3
//˼·���ӵڶ�������ʼ�ң������һ����С��0��ֱ�Ӳ�Ҫ
int main()
{
	int n ;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) //��������
	{
		cin >> a[i];
	}
	int sum = a[0];
	int max = a[0];
	//�ӵڶ�������ʼѰ��ʹ�����
	for (int i = 1; i < n; ++i)
	{
		if (sum >= 0)
		{
			sum = sum + a[i];
		}
		else
		{
			sum = a[i];
		}
		if (max < sum)
			max = sum;
	}
	cout << max;
	return 0;
}

#endif


//2.ͳ�ƻ���
//���������ַ�������str2����str1��ͳ�ƻ��Ĵ���
#if 0
bool HW(string str1)
{
	int length = str1.length();
	for (int i = 0; i < length; i++)
	{
		if (str1[i] != str1[length - 1])
			return false;
		length = length - 1;
	}
	return true;
}
int main()
{
	string str1, str2, temp;
	int count, len;
	while (cin >> str1 >> str2)
	{
		count = 0;
		temp = str1;//����ԭʼ�ַ�����������ƻ�
		len = str1.length() + 1;
		for (int i = 0; i < len; i++)
		{
			str1 = temp;
			str1.insert(i, str2);
			if (HW(str1))
			{
				count = count + 1;
			}
		}
		cout << count << endl;
	}
	return 0;
}

#endif


//3.�ַ���ת��������
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

#if 0

class Solution 
{
public:
	int StrToInt(string str) 
	{
		if (str.empty())
		{
			return 0;
		}
		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';//ת����ʽ
	}
		return symbol *sum;
	}

};

#endif

//4.����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��
//ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ :
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������

#if 0
int main()
{
	int W, H, i, j, count = 0;
	cin >> W >> H;
	if (W % 4 == 0 || H % 4 == 0)
	{
		count = W*H / 2;
	}
	else if (W % 2 == 0 && H % 2 == 0)
	{
		count = (W*H / 4 + 1) * 2;
	}
	else
	{
		count = W*H / 2 + 1;
	}
	cout << count << endl;
	return 0;
}
#endif

//int main()
//{
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//
//}


int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 3) << "," << (*p)[2] << endl;
	return 0;
}