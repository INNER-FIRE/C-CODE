#include<stdio.h>

#include<string.h>

void main()
{
  char ch1[255]="abcde";
  char ch2[100]="cd";
  char* ch;//���ڽ��ܷ���ֵ
  if((ch=strstr(ch1,ch2))==NULL)
{
  printf("-1\n");
}
  else{
	printf("%d\n",ch-ch1+1);//cde�ĵ�ַ��ȥabcde�ĵ�ַ+1
}
}