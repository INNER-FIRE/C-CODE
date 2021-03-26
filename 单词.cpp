#include<stdio.h>
#include<string.h>
int main()
{
	char a[100][50],b[50];  
	int i,j,k=0;
	
	while(gets(a[k])!=NULL)
	{
		k++;
	}
	
	for(i=0;i<k-1;i++) //冒泡排序，交换顺序
	{
		for(j=0;j<k-1;j++)
		{
			if(strcmp(a[j],a[j+1])>0) //A>B,返回正数;A<B,返回负数;A=B,返回0
			{
				strcpy(b,a[j]); //字符串用strcpy函数
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],b);
			}
		}
	}
	
	for(i=0;i<k;i++)
		printf("%s\n",a[i]);
	return 0;
}
