//һ������ʾ

//2021 3 21

//C�����ִ����� 

/******************************************************************************* 

  13.5.4 С�ڴ���  ��ʾһ���µ������б���������ʹ�ö�ά���顢�ַ�����֪ʶ�� 

********************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include <stdlib.h>

#define MAX_REMIND   50		//�����������(����)
#define MSG_LEN      60	    //ÿ���������ַ���󳤶�(����)

/*��������*/
int read_line (char str[], int n);		//���ַ�д�뵽�ַ����У��ַ��������Զ���n���ַ� 

/*������*/
int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 3];	//��3����Ϊday_str��2λ�Լ��ַ���ĩβ�Ŀ��ַ�1λ 
	char day_str[3], msg_str[MSG_LEN + 1];		//��2�����鳤���ж������˿��ַ���'\0'�������Զ���+1 
	int day, i, j, num_remind = 0; 				//num_remind�ǵ�ǰ¼�������� 
	
	for(;;)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
	    }
		
		//��¼�����ں����� 
		printf("Enter day and reminder: ");
		scanf("%2d",&day);
		if(day == 0)
			break;
		sprintf(day_str, "%2d", day);	//������day���뵽����day_str�в��Կ��ַ���β 
		read_line(msg_str,MSG_LEN);		//����������¼�뵽����msg_str�У�read_line�����ڲ������˿��ַ���β 
		
		//�����Ѱ����ڽ������� 
		for(i = 0; i < num_remind; i++)
			if(strcmp(day_str,reminders[i]) < 0)		//�����ǰ�����������С��֮ǰĳ�е����ڣ�����Ƚϣ�������forѭ�������������Ҫ�Ƕ�λ����i�� 
				break; 
		
		for(j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);		//ʵ�ʵ�ǰ��֮ǰ�����ڶ��Ѿ���˳�����кã��൱�ڲ����µ�δ֪���ڣ����������ж�����£��ƶ�һ�� 
		
		//�����ں����Ѻϲ���һ���ַ�����	
		strcpy(reminders[i],day_str);					//�ѵ�ǰ�����е����ں������ַ������ݽ��кϲ� 
		strcat(reminders[i],msg_str);
		
		num_remind++; 
		
	} 
	
	printf("\nDay Reminder\n");
	for(i = 0; i < num_remind; i++)
		printf("%s\n",reminders[i]);
			
	system("pause");	//����ú��������ʹ�ò�����exe�������У����ᷢ�����ˡ�Ҳ���Լ�����������ʹ��main�����޷����ؼ��ɡ���while(1)��getchar() �� 
	return 0;
	
}


int read_line (char str[], int n)
{
	int ch, i = 0;
	while((ch = getchar()) != '\n')	//�ж��Ƿ�Ϊ���з� 
		if( i < n)
			str[i++] = ch;
	str[i] = '\0';				//���ӿ��ַ���β 
	return i;	
}
