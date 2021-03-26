#include "trainandman.h"
#include <stdio.h>

#define HEADER1 " -------------------------------BOOK TICKET----------------------------------\n"
#define HEADER2 " |  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
#define HEADER3 " |----------|----------|----------|-----------|-----------|-----|------------|\n"
#define FORMAT  " |%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum

int saveflag=0 ;

/* 初始界面*/
void menu()
{
    puts("\n\n");//puts()函数用来向标准输出设备（屏幕）输出字符串并换行，
	//调用方式为，puts(s)；其中s为字符串字符（字符串数组名或字符串指针）
	// \t表示一个制表符
    puts("\t\t|------------------------------------------------------|");//输出到终端 
    puts("\t\t|                   Booking Tickets                    |");
    puts("\t\t|------------------------------------------------------|");
    puts("\t\t|       0:quit the system                              |");
    puts("\t\t|       1:Insert a train information                   |");
    puts("\t\t|       2:Search a train information                   |");
    puts("\t\t|       3:Book a train ticket                          |");
    puts("\t\t|       4:Modify the train information                 |");
    puts("\t\t|       5:Show the train information                   |");
    puts("\t\t|       6:save information to file                     |");
    puts("\t\t|------------------------------------------------------|");
}

/*保存火车信息*/
void SaveTrainInfo(Link l)
{
    FILE*fp ;
    Node*p ;
    int count=0,flag=1 ;
    fp=fopen("f:\\train.txt","wb");//打开只写的二进制文件 
    if(fp==NULL)
    {
        printf("the file can't be opened!");
        return ;
    }
    p=l->next ;
    while(p)//遍历p指针 
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)//fwrite向指定的磁盘文件中写入若干数据块 
        {
            p=p->next ;//指针指向下一位 
            count++;//记录保存的次数 
        }
        else
        {
            flag=0 ;
            break ;
        }
    }
    if(flag)
    {
        printf(" saved %d train records\n",count);
        saveflag=0 ;//保存结束，保存标志清零 
    }
    fclose(fp);//关闭文件 
}

/*保存订票人的信息*/
void SaveBookInfo(bookLink k)
{
    FILE*fp ;
    book *p ;
    int count=0,flag=1 ;
    fp=fopen("f:\\man.txt","wb");
    if(fp==NULL)
    {
        printf("the file can't be opened!");
        return ;
    }
    p=k->next ;
    while(p)
    {
	if(fwrite(p,sizeof(book),1,fp)==1)
        {
            p=p->next ;
            count++;
        }
        else
        {
            flag=0 ;
            break ;
        }
    }
    if(flag)
    {
        printf(" saved %d booking records\n",count);
        saveflag=0 ;
    }
    fclose(fp);
}

/*添加一个火车信息*/
void Traininfo(Link linkhead)
{
    struct node *p,*r,*s ;
    char num[10];
    r = linkhead ;
    s = linkhead->next ;
    while(r->next!=NULL)
    r=r->next ;
    while(1)//进入死循环 
    {
        printf("please input the number of the train(0-return)");
        scanf("%s",num);
        if(strcmp(num,"0")==0)
          break ;
        /*判断是否已经存在*/
        while(s)
        {
            if(strcmp(s->data.num,num)==0)//比较字符串 
            {
                printf("the train '%s'is existing!\n",num);
                return ;
            }
            s = s->next ;//指针后移 
        }
        p = (struct node*)malloc(sizeof(struct node));
        strcpy(p->data.num,num);/*输入车号*/
		printf("Input the city where the train will start:");
        scanf("%s",p->data.startcity);/*输入出发城市*/
        printf("Input the city where the train will reach:");
        scanf("%s",p->data.reachcity);/*输入到站城市*/
        printf("Input the time which the train take off:");
		scanf("%s",p->data.takeofftime);/*输入出发时间*/
        printf("Input the time which the train receive:");
		scanf("%s",&p->data.receivetime);/*输入到站时间*/
        printf("Input the price of ticket:");
        scanf("%d",&p->data.price);/*输入火车票价*/
        printf("Input the number of booked tickets:");
		scanf("%d",&p->data.ticketnum);/*输入预定票数*/
        p->next=NULL ;
        r->next=p ;/*插入到链表中*/
        r=p ;
    	saveflag = 1 ;//保存标志 
    }
}

/*打印火车票信息*/
void printheader() /*格式化输出表头*/
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}

void printdata(Node *q) /*格式化输出表中数据*/
{
	Node* p;
	p=q;
	printf(FORMAT,DATA);
}

/*查询火车信息*/
void searchtrain(Link l)

{
    Node *s[10],*r;
    int sel,k,i=0 ;
    char str1[5],str2[10];
    if(!l->next)
    {
        printf("There is not any record !");
        return ;
    }
    printf("Choose the way:\n1:according to the number of train;\n2:according to the city:\n");
    scanf("%d",&sel);/*输入选择的序号*/
    if(sel==1)//若输入序号等于1，则根据车次查询 
    {
        printf("Input the the number of train:");
        scanf("%s",str1);//输入火车车次 
        r=l->next;
		while(r!=NULL)//遍历指针r，若为空则跳出循环 
	        if(strcmp(r->data.num,str1)==0)/*检索是否有与输入的车号相匹配的火车*/
	        {
	            s[i]=r;
		    	i++;
		    	break;
	        }
	        else 
	            r=r->next;//没有查找到火车车次，则指针r后移一位 
    }
    else if(sel==2)//若输入序号等于2，则根据城市查询 
    {
        printf("Input the city  you want to go:");
        scanf("%s",str2);//输入查询的城市 
        r=l->next;
		while(r!=NULL)//遍历指针r，若为空则跳出循环
	        if(strcmp(r->data.reachcity,str2)==0)/*检索是否有与输入的城市相匹配的火车*/
	        {
	            s[i]=r;
		   	 	i++;//检索到有匹配的火车票信息 ，执行i++ 
		    	r=r->next;
	        }
	        else 
	            r=r->next;
    }
    	if(i==0)
		printf("can not find!");
	else
	{
		printheader();//输出表头 
    	for(k=0;k<i;k++)
		printdata(s[k]);//输出火车信息 
	}
}

/*订票子模块*/
void Bookticket(Link l,bookLink k)
{
    Node *r[10],*p ;
    char ch[2],tnum[10],str[10],str1[10],str2[10];
    book *q,*h ;
    int i=0,t=0,flag=0,dnum;
    q=k ;
    while(q->next!=NULL)
    	q=q->next ;
    printf("Input the city you want to go: ");
    scanf("%s",&str);/*输入要到达的城市*/
    p=l->next ;//p指向传入的参数指针i的下一位 
    while(p!=NULL)//遍历指针p 
    {
        if(strcmp(p->data.reachcity,str)==0)//比较输入的城市与输入的火车终点站是否匹配 
        {
            r[i]=p ;/*将满足条件的记录存到数组r中*/
            i++;
        }
        p=p->next ;
    }
    printf("\n\nthe number of record have %d\n",i);
    printheader();//输出表头 
    for(t=0;t<i;t++)
	    printdata(r[t]);//循环输出数组中的火车信息 
    if(i==0)
    printf("\nSorry!Can't find the train for you!\n");
    else
    {
        printf("\ndo you want to book it?<y/n>\n");
        scanf("%s",ch);
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否订票*/
        {
	    	h=(book*)malloc(sizeof(book));
            printf("Input your name: ");
            scanf("%s",&str1);//输入订票人姓名 
            strcpy(h->data.name,str1);//与存储的信息进行比较，看是否有重复的 
            printf("Input your id: ");
            scanf("%s",&str2);//输入身份证号 
            strcpy(h->data.num,str2);//与存储的信息进行比较，看是否有重复的
	    	printf("please input the number of the train:");
	    	scanf("%s",tnum);//输入要预定的车次 
	    	for(t=0;t<i;t++)
		    if(strcmp(r[t]->data.num,tnum)==0)//比较车次，看是否存在该车次 
		    {
		       if(r[t]->data.ticketnum<1)/*判断剩余的供订票的票数是否为0*/
		       {
			       printf("sorry,no ticket!");
			       sleep(2);//sleep()单位为秒
			       return;
		       }
		    	printf("remain %d tickets\n",r[t]->data.ticketnum);
	        	flag=1;
		    	break;
		    }
		    if(flag==0)
		    {
				printf("input error");
				sleep(2);
	            return;
		    }
		    printf("Input your bookNum: ");
	        scanf("%d",&dnum);//输入要预订的票数 
	        r[t]->data.ticketnum=r[t]->data.ticketnum-dnum;//引用结构数组的成员变量的成员   /*定票成功则可供订的票数相应减少*/
		    h->data.bookNum=dnum ;//将订票数赋给订票人信息 
	        h->next=NULL ;
		    q->next=h ;
		    q=h ;
            printf("\nLucky!you have booked a ticket!");
            getch();
            saveflag=1 ;
        }
    }
}

/*修改火车信息*/
void Modify(Link l)
{
    Node *p ;
    char tnum[10],ch ;
    p=l->next;
    if(!p)
    {
        printf("\nthere isn't record for you to modify!\n");
        return ;
    }
    else
    {
	    printf("\nDo you want to modify it?(y/n)\n");
        getchar();
        scanf("%c",&ch);//输入是否想要修改的字符 
        if(ch=='y'||ch=='Y')//判断字符 
        {
            printf("\nInput the number of the train:");
			scanf("%s",tnum);//输入需要修改的车次 
			while(p!=NULL)
				if(strcmp(p->data.num,tnum)==0)/*查找与输入的车号相匹配的记录*/
	    			break;
        		else
            		p=p->next;
            if(p)//遍历p，如果p不指向空，则执行if语句 
            {
                printf("Input new number of train:");
                scanf("%s",&p->data.num);
		    	printf("Input new city the train will start:");
                scanf("%s",&p->data.startcity);
                printf("Input new city the train will reach:");
                scanf("%s",&p->data.reachcity);
                printf("Input new time the train take off");
		    	scanf("%s",&p->data.takeofftime);
                printf("Input new time the train reach:");
		    	scanf("%s",&p->data.receivetime);
                printf("Input new price of the ticket::");
                scanf("%d",&p->data.price);
                printf("Input new number of people who have booked ticket:");
                scanf("%d",&p->data.ticketnum);
                printf("\nmodifying record is sucessful!\n");
                saveflag=1 ;//保存标志 
            }
            else
                printf("\tcan't find the record!");
        }
    }
}

/*自定义函数显示列车信息*/
void showtrain(Link l)
{
	Node *p;
	p=l->next;
	printheader();//输出列车表头 
	if(l->next==NULL)//判断有无可显示的信息 
		printf("no records!");
	else
		while(p!=NULL)//遍历p 
		{
			printdata(p);//输出所有火车数据 
			p=p->next;//p指针后移一位 
		}
}