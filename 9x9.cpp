
/**************************
*innerfire
*99乘法口诀表
*简单的for循环
****************************/
#include <stdio.h>

int main()
{
   int m,n;//定义两个数
   for(m = 1;m<=9;m++)
{
  for(n = 1;n<=9;n++)//前面数大于后面输出空白
   if (m>n)
    printf("        ");
  else
   printf("%d*%d=%d\t",m,n,m*n);//输出
   printf("\n");
}
   return 0;
}