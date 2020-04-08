#include <iostream>
using namespace std;

/*
最长公共子序列
我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。


建立一个dp矩阵，是两个字符串一个纵对应，一个横向对应。
dp[i][j]表示str1[0...i]和str2[0...j]的最长公共子序列的长度
求解 dp[i][j]为：
若str1[i] == str2[j]，则 dp[i][j] = max( dp[i-1][j],  dp[i][j-1],  dp[i-1][j-1]+1 )
若str1[i] != str2[j]，则 dp[i][j] = max( dp[i-1][j],  dp[i][j-1] )

最后返回dp[M-1][N-1]，M、N为两个字符串的长度
*/
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int aLength = A.length();
		int bLength = B.length();
		vector<vector<int>> dp(aLength, vector<int>(bLength, 0));

		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < aLength; i++)
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < bLength; j++)
		{
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j-1], dp[0][j]);
		}
	
			for (int i = 1; i<aLength; i++) 
			{
				for (int j = 1; j<bLength; j++) 
				{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j]) {

					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
			}
		cout << dp[aLength - 1][bLength - 1] << endl;
	}

	return 0;
}

//字符串计数：求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。

//求解大于str1的字符串个数以及大于str2的字符串个数，然后两者相减就能得到处于str1和str2之间的字符串个数
//对于求解长度len在[len1,len2]之间，且字典序大于某个字符串(str)的字符串个数：
//顺序遍历(i=0:n-1)str的每个字符str[i]，则若一个字符串destr大于str，则有两种情况：
//(1)destr第i个字符大于str[i]，则之后的字符无论是什么，destr都大于str
//(2)destr第i个字符等于str[i]，则i++，并继续讨论后续字符
//最后如果len>strLen，需要考虑destr前strLen位和str完全一样，则剩余位置字符可以是任意字符。
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int getcount(char str[], int strLen, int len1, int len2){
	int count = 0;
	for (int len = len1; len <= len2; len++){
		for (int i = 0; i < strLen && i < len; i++)
			count += (26 - (str[i] - 'a' + 1)) * pow(26, len - i - 1);
		if (len > strLen){
			count += pow(26, len - strLen);
		}
	}
	return count;
}
int main(){
	char str1[120];
	char str2[120];
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2){
		int strlen1 = strlen(str1);
		int strlen2 = strlen(str2);
		int count1 = getcount(str1, strlen1, len1, len2);
		int count2 = getcount(str2, strlen2, len1, len2);
		int count = count1 - count2 - 1;
		cout << count << endl;
	}
	return 0;
}
