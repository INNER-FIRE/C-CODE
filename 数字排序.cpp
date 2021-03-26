/*
*
*
*
*
*/

#include <stdio.h>

int num [20];

int main()
{
	int i = 0,n,j = 0,temp = 0;
	printf("");
	sacanf("");


	for(i = 1; i < n; i++ )
	{  
		temp = num[i];
		j = i-1;
		while(j>=0&&temp<num[j])
		{
			num[j+1] = num[j];
			j--;

		}
		num[j] = temp;

	}
	for(i = 0, i < n-1, i++)
		printf("%d",num[i]);
}





