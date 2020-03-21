
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* 删除输入字符串中所有在模式字符串中出现的字符
	* @param strSrc string字符串 源字符串
	* @param strPat string字符串 模式字符串
	* @return string字符串
	*/
	string stringFilter(string strSrc, string strPat) {
		// write code here
		       int count[256] = {0};
		for (int i = 0; i<strPat.size(); i++)
		{
			count[strPat[i]] = 1;
		}
		for (int i = 0; i<strSrc.size(); i++)
		{
			if (count[strSrc[i]] == 1)
			{
				strSrc = strSrc.erase(i, 1);
				i = i - 1;
			}
		}
		cout << strSrc << endl;
	}
};