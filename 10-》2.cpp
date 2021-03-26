#include <stdio.h>
void main()
{
    int c[32],i=0,n;
    scanf("%d", &n) ; //输入待转换整数n
    do {
        c[i++]=n%2;
        n/=2;
    } while(n!=0) ;
 
    for(i--;i>=0;i--)
        printf("%d",c[i] );
    printf("\n");
}
//除二取余//