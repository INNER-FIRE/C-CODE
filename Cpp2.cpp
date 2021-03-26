#include<stdio.h>
int main()
{
    int r=0;
    int c;
    while((c = getchar())!=EOF)
    {
        if(c == '0' || c=='1')
        {
            r<<=1;
            r|=c-'0';
        }
        else break;
    }
    printf("%d\n", r);
}