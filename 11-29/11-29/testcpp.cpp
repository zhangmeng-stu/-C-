#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//1.ϴ��
/*���ϴ����ʵ���ǰѺñ�123456�ֳ����ݣ�123��456��Ȼ���ȷŰ�123�Ž�
��СΪ6��vec�У����1_2_3_���ٰ�456������룬���142536�������һ��
ϴ�ƵĹ��̡�*/

vector<int> shuffle(vector<int> v) {
	vector<int> ans(v.size());
	int k = 0;
	for (int i = 0; i < v.size() / 2; i++) {
		ans[k] = v[i];
		k += 2;
	}
	k = v.size() - 1;
	for (int i = v.size() - 1; i >= v.size() / 2; i--) {
		ans[k] = v[i];
		k -= 2;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> poke(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> poke[i];
		}
		while (k--) {
			poke = shuffle(poke);
		}
		cout << poke[0];
		for (int i = 1; i < poke.size(); i++) {
			cout << " " << poke[i];
		}
		cout << endl;
	}
}
#endif 

#if 0
//2.MP3���λ��
//��n�׸�����ŷ���playlist�У����playlist={1,2��...n};
//��Ļ�ϳ��ֵĸ��������win_pos ��win_size��ͬȷ����
//cursor���ǹ��ָ���ĸ�����ŵ��±�
//���ľ��Ǹ�����������ֺ��ַ���ȷ��win_pos ��win_size�Լ�cursor.


int main()
{
	int n;
	string ins;//instruction��ָ��
	while (cin >> n >> ins)
	{
		int cursor = 0;//��궨λ
		int win_pos = 0;//����λ
		int win_size = 4;
		vector<int> playlist(n, 0);
		for (int i = 0; i < n; i++)
		{//��ʼ�������б�
			playlist[i] = i + 1;
		}
		if (n <= 4)
		{
			win_size = n;
			for (int i = 0; i < ins.length(); i++)
			{
				if (ins[i] == 'U')
				{
					cursor == 0 ? cursor = n - 1 : cursor--;
				}
				else
				{
					cursor == n - 1 ? cursor = 0 : cursor++;
				}
			}
		}
		else
		{
			for (int i = 0; i < ins.length(); i++)
			{
				if (ins[i] == 'U')
				{
					if (cursor == 0)
					{
						cursor = n - 1;//����Ƶ�����
						win_pos = n - 4;//����λҲҪ��Ӧ���ƶ�
					}
					else{
						if (cursor == win_pos)
						{
							win_pos--;//����ƶ�
							cursor--;//����λ��Ӧ���ƶ�
						}
						else
						{
							cursor--;//ֻ�й���ƶ�
						}
					}
				}
				else
				{//ins[i]=='D'
					if (cursor == n - 1)
					{
						cursor = 0;//����Ƶ�����
						win_pos = 0;//����λҲҪ��Ӧ���ƶ�
					}
					else
					{
						if (cursor == win_pos + 3)
						{
							cursor++;//����ƶ�
							win_pos++;//����λ��Ӧ���ƶ�
						}
						else
						{
							cursor++;//ֻ�й���ƶ�
						}
					}
				}
			}
		}
		for (int i = win_pos; i < win_pos + win_size; i++)
		{
			cout << playlist[i] << " ";
		}
		cout << endl;
		cout << playlist[cursor] << endl;
	}
	system("pause");
	return 0;
}
#endif 

#if 0
//С�׵�����֮·
int GOD(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return (a);
}
int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (c >= temp)
				c += temp;
			else
				c += GOD(c, temp);
		}
		cout << c << endl;
	}
	return 0;
}
#endif

//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�(�����Ѿ�����)
int main()
{
	string str;
	while (getline(cin, str))
	{
		size_t i, j;
		for ( i = 0; i < str.size(); i++)
		{
			char ch = str[i];
			for ( j = 0; j < str.size(); j++)
			{
				if (ch == str[j] && i != j)
					break;
			}
			if (j == str.size())
				break;
		}
		if (i == str.size())
			cout << "-1" << endl;
		else
			cout << str[i] << endl;
	}
	return 0;
}