/**************************
*方程求根
*innerfire
****************************/
#include <stdio.h>

#include <math.h>//math库 sqrt函数

 

void main()

{

    double a,b,c;                                //定义系数变量

    double x1,x2,p;                              //定义根变量和表达式的变量值

    printf("请输入a,b,c:");                     

    scanf("%lf%lf%lf",&a,&b,&c);               

    printf("\n");                            
    p=b*b-4*a*c;                            //给表达式赋值

    x1=(-b+sqrt(p))/(2*a);                           //根1

    x2=(-b-sqrt(p))/(2*a);                           //跟2

    printf("x1=%f,x2=%f\n",x1,x2);                   //输出

}