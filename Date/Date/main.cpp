#include "Date.h"
int main()
{
   Date d1(2019 ,7, 30);
//   Date t = d1 + 10;
//   Date t = d1 - 100;
   Date d2(2020, 1, 1);
   int t = d2 - d1;
   cout << t << endl;
   return 0;
	
}