#include <iostream>
#include <string>
#include <vector>
using namespace std;

//1.�ַ������ҳ�������ִ�
//˼·�������ַ������������ֺ�ʼѭ����ֱ���������ֺ�����ѭ������������ֵĳ���
//��¼�뱣����󳤶�

#if 0
int main()
{
	string str;
	while (cin >> str)  //ѭ������
	{
		int i;
		int max = 0;
		string s1;
		string s2;
		for (i = 0; i < str.size(); i++)//�����ַ���
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				s1 += str[i];
				while (str[i] >= '0' && str[i] <= '9')
				{
					i++;
					s1 += str[i];
				}
				if (s1.size() > max)
				{
					max = s1.size();
					s2 = s1;
				}
				else if (s1.size() == max)
				{
					s2 += s1;
				}
			}
			s1.clear();
		}
		cout << s2 << ',' << max << endl;
	}
	return 0;
}

#endif

#if 0
//2.�����г��ִ�����������
//˼·���������鱣������ֵ��һ��������һ�����֣�һ��������������һ������ʱ��
//������֮ǰ�����������ͬ���������1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1��
//��������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
		{
			return 0;
		}
		//����ÿ��Ԫ�أ�����¼������
		int result = numbers[0];
		int count = 1;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
			{
				//����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				count = 1;
			}
			else if (numbers[i] == result)
			{
				++count;
			}
			else
			{
				--count;
			}
		}
		//�ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++count;
		}
		return (count>numbers.size() / 2) ? result : 0;
	}
};

#endif



#if 0
//3.����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������

void Trans(int m, int n)
{
	if (n<1 || n>16)
		return;
	if (m < 0)
	{
		m = -m;
		cout << "-";
	}
	vector<int> a;//���ת���������
	while (m)
	{
		a.push_back(m%n);
		m = m / n;
	}

	vector<int>::reverse_iterator it = a.rbegin();//���������
	while (it != a.rend())
	{
		if (*it == 10)
			cout << "A";
		else if(*it == 11)
			cout << "B";
		else if (*it == 12)
			cout << "C";
		else if (*it == 13)
			cout << "D"; 
		else if (*it == 14)
			cout << "E";
		else if (*it == 15)
			cout << "F";
		else
			cout << *it;
		it++;
	}
	cout << endl;
}
int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	Trans(m, n);
	return 0;
}

#endif 

//�����ǹ�
//��Ŀ��
//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C��
int main()
{
	int a, b, c, d;
	int A, B, C;
	while (cin >> a >> b >> c >> d)
	{
		//a = A - B; b = B - C; c = A + B; d = B + C;
		A = (a + c) / 2;
		B = (b + d) / 2;
		C = (d - b) / 2;
		if (A - B == a && B - C == b && A + B == c && B + C == d)
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}