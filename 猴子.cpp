#include <stdio.h>
#include <cohio.h>

int Monkey(int n, int k)
{ 
 int sum ;
 if(n==k)
 sum=1;
else
 sum=2*Monkey(n+1,k)+1);
return sum;
}

void main()
{
 int k=10,sum=0;
 printf("请输入猴子吃桃的天数，默认为10天\nk=")；
 fflush(stdin);
 scanf("%d",&k);
 sum=Monkey(1,k);
 printf("猴子第一天摘桃个数为=%d",sum);
 getche();
}
