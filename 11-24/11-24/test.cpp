#include <iostream>
#include <vector>
#include <string>

using namespace std;

#if 0
//1.��������������������1�ĸ���

int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumberOf1(n) << endl;
	}
	return 0;
}
#endif

/*2.�ڵ����������n����ɫ�����ף����׷������֣�
����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�
������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��
ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס�
���ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,
�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26��
��һ����������һ�ֺϷ�������

//˼·:
1. �Ȱ�����Ϊ0��ƥ��϶����ɹ��ģ�����������ȫ���ó���
2. �ҳ�������������С�ͣ�������0���׵ģ����飬�Ѹ�������������������
   ȫ���ˣ�ʣ����С�ģ���һ��
3. �ٴӶ�������У��ó����һ�����Ϳ���ƥ��*/

#if 0
class Gloves 
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) 
	{
			int min = 0, lmin = 0, rmin = 0;
		int lm = 26, rm = 26;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				min += left[i];
				min += right[i];
			}
			else
			{
				lmin += left[i];
				rmin += right[i];
				if (left[i] < lm)
					lm = left[i];
				if (right[i] < rm)
					rm = right[i];
			}
		}
		min += lmin > rmin ? (rmin - rm) : (lmin - lm);
		return min + 2;
	}
};

#endif

#if 0
/*
3.��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��*/

int BeatyCount(int num)
{
	int count = 0;
	for (int j = 3; j <= num; j++)
	{
		int sum = 0;
		for (int i = 1; i <= j / 2 + 1; i++)
		{
			if (j%i == 0)
			{
				sum += i;
			}
		}
		if (sum == j)
			count++;
	}
	return count;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << BeatyCount(num) << endl;
	}
	return 0;
}
#endif

//4.�˿��ƴ�С
/*�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ��������
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��磺4 4 4 4-joker JOKER��
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
��������
��1������ÿ���ƿ����Ǹ��ӡ����ӡ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ���
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������*/


// ���ݸ������ŷָ��ַ���
vector<string> split(const string &ip, char ch)
{
	vector<string> result;
	int start = 0;
	for (int i = 0; i < ip.size(); ++i)
	{
		if (ip[i] == ch)
		{
			result.push_back(string(ip.begin() + start, ip.begin() + i));
			start = i + 1;
		}
	}
	if (start < ip.size())
	{
		result.push_back(string(ip.begin() + start, ip.end()));
	}
	return result;
}

// �ж��������Ƿ���joker
int has_joker(vector<string> &hand)
{
	int ret = 0;
	for (int i = 0; i < hand.size(); ++i)
	{
		if (hand[i] == "joker")
			ret |= 0x01;
		else if (hand[i] == "JOKER")
			ret |= 0x10;
	}
	return ret;
}

// ������ת������Ӧ����ֵ�����Ƚϴ�С
// Ҳ����д��һ�ű�ֱ�Ӳ���ȡ����
int hand2int(string &left)
{
	if (left.size() == 2) // 10
		return 10;
	else if (isdigit(left[0])) // 3-9
		return left[0] - '0';
	else if (left[0] == 'J')
		return 11;
	else if (left[0] == 'Q')
		return 12;
	else if (left[0] == 'K')
		return 13;
	else if (left[0] == 'A')
		return 14;
	return -1;
}

int main(void)
{
	string line;
	while (getline(cin, line))
	{
		vector<string> hands = split(line, '-');
		vector<string> left_hand = split(hands[0], ' ');
		vector<string> right_hand = split(hands[1], ' ');

		int who_is_big = 0; // 0���ܱȽϣ�1���-1�Ҵ�
		// �Ȱ�joker������
		int left_joker = has_joker(left_hand);
		int right_joker = has_joker(right_hand);

		if (left_joker != right_joker) // ������joker�����,ֱ���ж�joker�ͺ���
			who_is_big = (left_joker > right_joker ? 1 : -1);
		else if (left_hand.size() == right_hand.size()) // ������һ�������
			who_is_big = (hand2int(left_hand[0]) > hand2int(right_hand[0]) ? 1 : -1);
		else // ��������һ�������
		{
			// joker���ÿ����ˣ�ֻ��ը����
			if (left_hand.size() == 4)
				who_is_big = 1;
			else if (right_hand.size() == 4)
				who_is_big = -1;
		}
		if (who_is_big == 1)
			cout << hands[0] << endl;
		else if (who_is_big == -1)
			cout << hands[1] << endl;
		else
			cout << "ERROR" << endl;

		cin.ignore();
	}
	return 0;
}