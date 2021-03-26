//一个月提示

//2021 3 21

//C语言现代方法 

/******************************************************************************* 

  13.5.4 小节代码  显示一个月的提醒列表，本例中有使用二维数组、字符串等知识点 

********************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include <stdlib.h>

#define MAX_REMIND   50		//最大提醒数量(行数)
#define MSG_LEN      60	    //每条提醒中字符最大长度(列数)

/*函数声明*/
int read_line (char str[], int n);		//把字符写入到字符串中，字符串最大可以读入n个字符 

/*主函数*/
int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 3];	//加3是因为day_str有2位以及字符串末尾的空字符1位 
	char day_str[3], msg_str[MSG_LEN + 1];		//这2个数组长度中都包含了空字符（'\0'），所以都有+1 
	int day, i, j, num_remind = 0; 				//num_remind是当前录入提醒数 
	
	for(;;)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
	    }
		
		//先录入日期和提醒 
		printf("Enter day and reminder: ");
		scanf("%2d",&day);
		if(day == 0)
			break;
		sprintf(day_str, "%2d", day);	//把整型day传入到数组day_str中并以空字符结尾 
		read_line(msg_str,MSG_LEN);		//把提醒内容录入到数组msg_str中，read_line函数内部增加了空字符结尾 
		
		//对提醒按日期进行排序 
		for(i = 0; i < num_remind; i++)
			if(strcmp(day_str,reminders[i]) < 0)		//如果当前行输入的日期小于之前某行的日期（逐个比较）就跳出for循环，这个步骤主要是定位到第i行 
				break; 
		
		for(j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);		//实际当前行之前的日期都已经按顺序排列好，相当于插入新的未知日期，后面所有行都外后（下）移动一行 
		
		//把日期和提醒合并到一个字符串中	
		strcpy(reminders[i],day_str);					//把当前日期行的日期和提醒字符串内容进行合并 
		strcat(reminders[i],msg_str);
		
		num_remind++; 
		
	} 
	
	printf("\nDay Reminder\n");
	for(i = 0; i < num_remind; i++)
		printf("%s\n",reminders[i]);
			
	system("pause");	//加入该函数后可以使得产生的exe单独运行，不会发生闪退。也可以加入其它函数使得main函数无法返回即可。如while(1)、getchar() 等 
	return 0;
	
}


int read_line (char str[], int n)
{
	int ch, i = 0;
	while((ch = getchar()) != '\n')	//判断是否为换行符 
		if( i < n)
			str[i++] = ch;
	str[i] = '\0';				//增加空字符结尾 
	return i;	
}
