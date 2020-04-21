#include <iostream>
using namespace std;
#include <vector>

/*
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/
class Solution{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (input.empty() || input.size()<k)
			return result;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; i++)
		{
			result.push_back(input[i]);
		}
		return result;
	}
};

#include <string>
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> array;
		if (str.size() == 0)
			return array;
		Permutation(array, str, 0);
		sort(array.begin(), array.end());
		return array;
	}
	void Permutation(vector<string>&array, string str, int begin)
	{
		if (begin == str.size() - 1)
			array.push_back(str);
		for (int i = begin; i <= str.size()-1; i++)
		{
			if (i != begin&&str[i] == str[begin])
				continue;
			swap(str[i], str[begin]);
			Permutation(array, str, begin + 1);
			swap(str[i], str[begin]);
		}
	}
};