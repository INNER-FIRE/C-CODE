#include "trainandman.h"
#include <stdio.h>

#define HEADER1 " -------------------------------BOOK TICKET----------------------------------\n"
#define HEADER2 " |  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
#define HEADER3 " |----------|----------|----------|-----------|-----------|-----|------------|\n"
#define FORMAT  " |%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum

int saveflag=0 ;

/* ��ʼ����*/
void menu()
{
    puts("\n\n");//puts()�����������׼����豸����Ļ������ַ��������У�
	//���÷�ʽΪ��puts(s)������sΪ�ַ����ַ����ַ������������ַ���ָ�룩
	// \t��ʾһ���Ʊ��
    puts("\t\t|------------------------------------------------------|");//������ն� 
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

/*�������Ϣ*/
void SaveTrainInfo(Link l)
{
    FILE*fp ;
    Node*p ;
    int count=0,flag=1 ;
    fp=fopen("f:\\train.txt","wb");//��ֻд�Ķ������ļ� 
    if(fp==NULL)
    {
        printf("the file can't be opened!");
        return ;
    }
    p=l->next ;
    while(p)//����pָ�� 
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)//fwrite��ָ���Ĵ����ļ���д���������ݿ� 
        {
            p=p->next ;//ָ��ָ����һλ 
            count++;//��¼����Ĵ��� 
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
        saveflag=0 ;//��������������־���� 
    }
    fclose(fp);//�ر��ļ� 
}

/*���涩Ʊ�˵���Ϣ*/
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

/*���һ������Ϣ*/
void Traininfo(Link linkhead)
{
    struct node *p,*r,*s ;
    char num[10];
    r = linkhead ;
    s = linkhead->next ;
    while(r->next!=NULL)
    r=r->next ;
    while(1)//������ѭ�� 
    {
        printf("please input the number of the train(0-return)");
        scanf("%s",num);
        if(strcmp(num,"0")==0)
          break ;
        /*�ж��Ƿ��Ѿ�����*/
        while(s)
        {
            if(strcmp(s->data.num,num)==0)//�Ƚ��ַ��� 
            {
                printf("the train '%s'is existing!\n",num);
                return ;
            }
            s = s->next ;//ָ����� 
        }
        p = (struct node*)malloc(sizeof(struct node));
        strcpy(p->data.num,num);/*���복��*/
		printf("Input the city where the train will start:");
        scanf("%s",p->data.startcity);/*�����������*/
        printf("Input the city where the train will reach:");
        scanf("%s",p->data.reachcity);/*���뵽վ����*/
        printf("Input the time which the train take off:");
		scanf("%s",p->data.takeofftime);/*�������ʱ��*/
        printf("Input the time which the train receive:");
		scanf("%s",&p->data.receivetime);/*���뵽վʱ��*/
        printf("Input the price of ticket:");
        scanf("%d",&p->data.price);/*�����Ʊ��*/
        printf("Input the number of booked tickets:");
		scanf("%d",&p->data.ticketnum);/*����Ԥ��Ʊ��*/
        p->next=NULL ;
        r->next=p ;/*���뵽������*/
        r=p ;
    	saveflag = 1 ;//�����־ 
    }
}

/*��ӡ��Ʊ��Ϣ*/
void printheader() /*��ʽ�������ͷ*/
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}

void printdata(Node *q) /*��ʽ�������������*/
{
	Node* p;
	p=q;
	printf(FORMAT,DATA);
}

/*��ѯ����Ϣ*/
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
    scanf("%d",&sel);/*����ѡ������*/
    if(sel==1)//��������ŵ���1������ݳ��β�ѯ 
    {
        printf("Input the the number of train:");
        scanf("%s",str1);//����𳵳��� 
        r=l->next;
		while(r!=NULL)//����ָ��r����Ϊ��������ѭ�� 
	        if(strcmp(r->data.num,str1)==0)/*�����Ƿ���������ĳ�����ƥ��Ļ�*/
	        {
	            s[i]=r;
		    	i++;
		    	break;
	        }
	        else 
	            r=r->next;//û�в��ҵ��𳵳��Σ���ָ��r����һλ 
    }
    else if(sel==2)//��������ŵ���2������ݳ��в�ѯ 
    {
        printf("Input the city  you want to go:");
        scanf("%s",str2);//�����ѯ�ĳ��� 
        r=l->next;
		while(r!=NULL)//����ָ��r����Ϊ��������ѭ��
	        if(strcmp(r->data.reachcity,str2)==0)/*�����Ƿ���������ĳ�����ƥ��Ļ�*/
	        {
	            s[i]=r;
		   	 	i++;//��������ƥ��Ļ�Ʊ��Ϣ ��ִ��i++ 
		    	r=r->next;
	        }
	        else 
	            r=r->next;
    }
    	if(i==0)
		printf("can not find!");
	else
	{
		printheader();//�����ͷ 
    	for(k=0;k<i;k++)
		printdata(s[k]);//�������Ϣ 
	}
}

/*��Ʊ��ģ��*/
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
    scanf("%s",&str);/*����Ҫ����ĳ���*/
    p=l->next ;//pָ����Ĳ���ָ��i����һλ 
    while(p!=NULL)//����ָ��p 
    {
        if(strcmp(p->data.reachcity,str)==0)//�Ƚ�����ĳ���������Ļ��յ�վ�Ƿ�ƥ�� 
        {
            r[i]=p ;/*�����������ļ�¼�浽����r��*/
            i++;
        }
        p=p->next ;
    }
    printf("\n\nthe number of record have %d\n",i);
    printheader();//�����ͷ 
    for(t=0;t<i;t++)
	    printdata(r[t]);//ѭ����������еĻ���Ϣ 
    if(i==0)
    printf("\nSorry!Can't find the train for you!\n");
    else
    {
        printf("\ndo you want to book it?<y/n>\n");
        scanf("%s",ch);
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ʊ*/
        {
	    	h=(book*)malloc(sizeof(book));
            printf("Input your name: ");
            scanf("%s",&str1);//���붩Ʊ������ 
            strcpy(h->data.name,str1);//��洢����Ϣ���бȽϣ����Ƿ����ظ��� 
            printf("Input your id: ");
            scanf("%s",&str2);//�������֤�� 
            strcpy(h->data.num,str2);//��洢����Ϣ���бȽϣ����Ƿ����ظ���
	    	printf("please input the number of the train:");
	    	scanf("%s",tnum);//����ҪԤ���ĳ��� 
	    	for(t=0;t<i;t++)
		    if(strcmp(r[t]->data.num,tnum)==0)//�Ƚϳ��Σ����Ƿ���ڸó��� 
		    {
		       if(r[t]->data.ticketnum<1)/*�ж�ʣ��Ĺ���Ʊ��Ʊ���Ƿ�Ϊ0*/
		       {
			       printf("sorry,no ticket!");
			       sleep(2);//sleep()��λΪ��
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
	        scanf("%d",&dnum);//����ҪԤ����Ʊ�� 
	        r[t]->data.ticketnum=r[t]->data.ticketnum-dnum;//���ýṹ����ĳ�Ա�����ĳ�Ա   /*��Ʊ�ɹ���ɹ�����Ʊ����Ӧ����*/
		    h->data.bookNum=dnum ;//����Ʊ��������Ʊ����Ϣ 
	        h->next=NULL ;
		    q->next=h ;
		    q=h ;
            printf("\nLucky!you have booked a ticket!");
            getch();
            saveflag=1 ;
        }
    }
}

/*�޸Ļ���Ϣ*/
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
        scanf("%c",&ch);//�����Ƿ���Ҫ�޸ĵ��ַ� 
        if(ch=='y'||ch=='Y')//�ж��ַ� 
        {
            printf("\nInput the number of the train:");
			scanf("%s",tnum);//������Ҫ�޸ĵĳ��� 
			while(p!=NULL)
				if(strcmp(p->data.num,tnum)==0)/*����������ĳ�����ƥ��ļ�¼*/
	    			break;
        		else
            		p=p->next;
            if(p)//����p�����p��ָ��գ���ִ��if��� 
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
                saveflag=1 ;//�����־ 
            }
            else
                printf("\tcan't find the record!");
        }
    }
}

/*�Զ��庯����ʾ�г���Ϣ*/
void showtrain(Link l)
{
	Node *p;
	p=l->next;
	printheader();//����г���ͷ 
	if(l->next==NULL)//�ж����޿���ʾ����Ϣ 
		printf("no records!");
	else
		while(p!=NULL)//����p 
		{
			printdata(p);//������л����� 
			p=p->next;//pָ�����һλ 
		}
}