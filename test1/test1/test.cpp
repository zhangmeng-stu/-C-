
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* ɾ�������ַ�����������ģʽ�ַ����г��ֵ��ַ�
	* @param strSrc string�ַ��� Դ�ַ���
	* @param strPat string�ַ��� ģʽ�ַ���
	* @return string�ַ���
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