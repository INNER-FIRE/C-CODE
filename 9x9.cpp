
/**************************
*innerfire
*99�˷��ھ���
*�򵥵�forѭ��
****************************/
#include <stdio.h>

int main()
{
   int m,n;//����������
   for(m = 1;m<=9;m++)
{
  for(n = 1;n<=9;n++)//ǰ�������ں�������հ�
   if (m>n)
    printf("        ");
  else
   printf("%d*%d=%d\t",m,n,m*n);//���
   printf("\n");
}
   return 0;
}