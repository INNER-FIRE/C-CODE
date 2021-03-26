#include<stdio.h>

#include<string.h>

void main()
{
  char ch1[255]="abcde";
  char ch2[100]="cd";
  char* ch;//用于接受返回值
  if((ch=strstr(ch1,ch2))==NULL)
{
  printf("-1\n");
}
  else{
	printf("%d\n",ch-ch1+1);//cde的地址减去abcde的地址+1
}
}