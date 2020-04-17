#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


/*

搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，
即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。
小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
思路：体重相同时， 只有身高相同才能叠。
 体重升序排列， 体重相同时，按身高降序排列（为了使index递增时， 不让体重相等，身高不等的人计为有效）。
接下来就是按照身高数据进行最大升序子序列。
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
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
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