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