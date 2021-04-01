/*****************************
猴子吃桃问题
逆向求解
innerfire
  ****************************/
#include<stdio.h>

void main() 
{
	int n = 1, day = 1;
	printf("请输入天数\n");
	scanf("%d", &day);
	for (int i = 1; i < day; i++) 
	{
		//反向求解，数列的通项公式为n=(n+1)*2
		n = (n + 1) * 2;
	}
	printf("桃子个数为:%d\n", n);
}
