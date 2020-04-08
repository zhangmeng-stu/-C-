#include <iostream>
using namespace std;

/*
�����������
�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�


����һ��dp�����������ַ���һ���ݶ�Ӧ��һ�������Ӧ��
dp[i][j]��ʾstr1[0...i]��str2[0...j]������������еĳ���
��� dp[i][j]Ϊ��
��str1[i] == str2[j]���� dp[i][j] = max( dp[i-1][j],  dp[i][j-1],  dp[i-1][j-1]+1 )
��str1[i] != str2[j]���� dp[i][j] = max( dp[i-1][j],  dp[i][j-1] )

��󷵻�dp[M-1][N-1]��M��NΪ�����ַ����ĳ���
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

//�ַ������������ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��

//������str1���ַ��������Լ�����str2���ַ���������Ȼ������������ܵõ�����str1��str2֮����ַ�������
//������ⳤ��len��[len1,len2]֮�䣬���ֵ������ĳ���ַ���(str)���ַ���������
//˳�����(i=0:n-1)str��ÿ���ַ�str[i]������һ���ַ���destr����str���������������
//(1)destr��i���ַ�����str[i]����֮����ַ�������ʲô��destr������str
//(2)destr��i���ַ�����str[i]����i++�����������ۺ����ַ�
//������len>strLen����Ҫ����destrǰstrLenλ��str��ȫһ������ʣ��λ���ַ������������ַ���
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
