/*****************************
���ӳ�������
�������
innerfire
  ****************************/
#include<stdio.h>

void main() 
{
	int n = 1, day = 1;
	printf("����������\n");
	scanf("%d", &day);
	for (int i = 1; i < day; i++) 
	{
		//������⣬���е�ͨ�ʽΪn=(n+1)*2
		n = (n + 1) * 2;
	}
	printf("���Ӹ���Ϊ:%d\n", n);
}
