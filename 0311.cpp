#include <stdio.h>

#include <math.h>

 

void main()

{

    double a,b,c;                                /*����ϵ������*/

    double x1,x2,p;                              /*����������ͱ���ʽ�ı���ֵ*/

    printf("������a,b,c:");                     

    scanf("%lf%lf%lf",&a,&b,&c);               

    printf("\n");                            
    p=b*b-4*a*c;                            /*������ʽ��ֵ*/

    x1=(-b+sqrt(p))/(2*a);                           /*��1��ֵ*/

    x2=(-b-sqrt(p))/(2*a);                           /*��2��ֵ*/

    printf("x1=%f,x2=%f\n",x1,x2);                   /*�����������ֵ*/

}