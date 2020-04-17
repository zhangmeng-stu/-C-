#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


/*

�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ��������ų����ʹ��������ǰ�������ۣ�С�����������˽⵽�� ��Ϸ���������һ���½�Ŀ������޺�������
����Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� �ų���Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա�����⡣
С�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա��������أ����Һܿ��ҵ�������޺�������Ա���С� ����������Ҳ�õ�������һ��������ر����ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��
˼·��������ͬʱ�� ֻ�������ͬ���ܵ���
 �����������У� ������ͬʱ������߽������У�Ϊ��ʹindex����ʱ�� ����������ȣ���߲��ȵ��˼�Ϊ��Ч����
���������ǰ���������ݽ���������������С�
*/
struct unit
{
	int id;
	int weight;
	int height;
};
bool cmp(unit u1, unit u2){
	if (u1.weight != u2.weight)
		return u1.weight < u2.weight;
	else
		return u1.height > u2.height;
}
int main(){
	int n;
	while (cin >> n)
	{
		vector<unit> vec(n);
		for (int i = 0; i < n; i++){
			scanf("%d%d%d", &vec[i].id, &vec[i].weight, &vec[i].height);
		}
		sort(vec.begin(), vec.end(), cmp);
		vector<int> dp(n, 1);
		int max = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++){
				if (dp[j] + 1 > dp[i] && vec[i].height >= vec[j].height){
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > max)
				max = dp[i];
		}
		cout << max << endl;
	}
}

/*
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n, k, d;
	cin >> n;

	if (n < 1) return 0;
	vector<int> stud(n);
	for (int i = 0; i < n; i++){
		cin >> stud[i];
	}
	cin >> k >> d;
	if (k>n || k < 1 || d < 1) return 0;

	vector<vector<long long>> maxMul(n, vector<long long>(k + 1, 0));
	vector<vector<long long>> minMul(n, vector<long long>(k + 1, 0));

	for (int i = 0; i < n; i++){
		maxMul[i][1] = stud[i];
		minMul[i][1] = stud[i];
	}

	for (int i = 2; i <= k; i++){
		for (int j = 0; j <n; j++){
			for (int m = 1; m <= d&&j >= m; m++){
				maxMul[j][i] = max(maxMul[j][i], max(maxMul[j - m][i - 1] * stud[j], minMul[j - m][i - 1] * stud[j]));
				minMul[j][i] = min(minMul[j][i], min(minMul[j - m][i - 1] * stud[j], maxMul[j - m][i - 1] * stud[j]));
			}
		}
	}

	long long maxMulResult = 1LL << 63;
	for (int i = 0; i < n; i++){
		maxMulResult = max(maxMulResult, maxMul[i][k]);
	}

	cout << maxMulResult;
	return 0;
}