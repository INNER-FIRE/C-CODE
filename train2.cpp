#include <conio.h>
//conio��Console Input/Output������̨����������ļ�д�����ж�����ͨ������̨���������������������ĺ�������Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����������getch()�����ȵȡ�
#include <stdio.h>
//stdio ����ָ ��standard input & output"����׼���������,����c�����е� printf("%d",i); scanf("%d",&i);�Ⱥ���
#include <stdlib.h>
//stdlib ͷ�ļ���standard library��׼��ͷ�ļ�,��malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()�ȵ�
#include <string.h>
//C���Ա�׼����һ�����õ�ͷ�ļ�����ʹ�õ��ַ�����ʱ��Ҫʹ�á�
//strlen���ַ�������
//strcmp�Ƚ�2���ַ����Ƿ�һ��
//strcat�ַ������Ӳ���
//strcpy�ַ�����������
//strncat�ַ������Ӳ���(ǰn���ַ�)
//strncpy�ַ�����������(ǰn���ַ�)
//strchr��ѯ�ִ�
//strstr ��ѯ�Ӵ�
#include <dos.h>
#include "trainandman.h"

//#define HEADER1 " -------------------------------BOOK TICKET----------------------------------\n"
//#define HEADER2 " |  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
//#define HEADER3 " |----------|----------|----------|-----------|-----------|-----|------------|\n"
//#define FORMAT  " |%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
//#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum


int main()
{
	FILE*fp1,*fp2 ;//�ļ�����ָ�� 
	Node *p,*r ;//����Ϣ����Ľ��ṹָ�� 
    char ch1,ch2 ;
    Link l ;//����Ϣ����Ľ��ṹָ��
    bookLink k ;//��Ʊ������Ľ��ṹָ�� 
    book *t,*h ;//��Ʊ������Ľ��ṹָ�� 
    int sel ;
    l=(Node*)malloc(sizeof(Node));//��̬�ڴ���䣬��������һ��������ָ����С���ڴ������
	//���޷�֪���ڴ����λ�õ�ʱ����Ҫ���������ڴ�ռ䣬����Ҫ�õ���̬�ķ����ڴ档
	//һ�����free�������ʹ��
    l->next=NULL ;
    r=l ;
    k=(book*)malloc(sizeof(book));//ǿ������װ�� 
    k->next=NULL ;
    h=k ;
    
	fp1=fopen("f:\\train.txt","ab+");/*�򿪴洢��Ʊ��Ϣ���ļ�*/
	//���ļ������ļ����ڴ棬�����ļ���Ϣ�ṹָ��    rb+ ��д��һ���������ļ���ֻ�����д���ݡ� ab+ ��д��һ���������ļ�������������ļ�ĩ׷�����ݡ�
    if((fp1==NULL))//�ļ�û�д򿪳ɹ� 
    {
        printf("can't open the file!");
        return 0 ;
    }
    while(!feof(fp1))//�����ļ����Ƿ񵽽�β //feof��C���Ա�׼�⺯������ԭ����stdio.h�У��书���Ǽ�����ϵ��ļ�������������ļ��������򷵻ط�0ֵ�����򷵻�0
    {
        p=(Node*)malloc(sizeof(Node));//Ϊp��̬�����ڴ� 
        if(fread(p,sizeof(Node),1,fp1)==1)/*��ָ�������ļ���ȡ��¼*/
        {
            p->next=NULL ;
            r->next=p ;/*��������*/
            r=p ;
        }
    }
    fclose(fp1);//�ر��ļ� 
    fp2=fopen("f:\\man.txt","ab+");
    if((fp2==NULL))
    {
        printf("can't open the file!");
        return 0 ;
    }
    
    while(!feof(fp2))
    {
        t=(book*)malloc(sizeof(book));
        if(fread(t,sizeof(book),1,fp2)==1)
        {
            t->next=NULL ;
            h->next=t ;
            h=t ;
        }
    }
    fclose(fp2);
    
    while(1)
    {
        system("CLS");//system�������ͷ�ļ�<stdlib.h>�󷽿ɵ��á�
        //system("CLS")����ʵ������������
        menu();
        printf("\tplease choose (0~6):  ");
        scanf("%d",&sel);
        system("CLS"); 
    	if(sel==0)
        {
	    if(saveflag==1)//���˳�ʱ�ж���Ϣ�Ƿ񱣴�
           {
                getchar();
                //getchar��һ��int�͵ķ���ֵ.���������getcharʱ.
				//����͵����û�����.�û�������ַ�������ڼ��̻�������.
				//ֱ���û����س�Ϊֹ(�س��ַ�Ҳ���ڻ�������).
				//���û�����س�֮��,getchar�ſ�ʼ��stdio����ÿ�ζ���һ���ַ�.
				//getchar�����ķ���ֵ���û�����ĵ�һ���ַ���ASCII��,
				//�������-1,�ҽ��û�������ַ����Ե���Ļ.
				//���û��ڰ��س�֮ǰ�����˲�ֹһ���ַ�,�����ַ��ᱣ���ڼ��̻�������,
				//�ȴ�����getchar���ö�ȡ.Ҳ����˵,������getchar���ò���ȴ��û�����,
				//��ֱ�Ӷ�ȡ�������е��ַ�,ֱ���������е��ַ�����Ϊ��,�ŵȴ��û�����.
                printf("\nthe file have been changed!do you want to save it(y/n)?\n");
                scanf("%c",&ch1);
                if(ch1=='y'||ch1=='Y')
                {
					SaveBookInfo(k);//���涩Ʊ�˵���Ϣ
                    SaveTrainInfo(l);//�������Ϣ
                }
            }
            printf("\nThank you!!You are welcome too\n");
            break ;//��������ѭ�� 

        }
        switch(sel)//���������selֵ��ͬѡ����Ӧ����
        {
            case 1 :
              Traininfo(l);break ;//���һ������Ϣ
            case 2 :
              searchtrain(l);break ;//��ѯ����Ϣ
            case 3 :
              Bookticket(l,k);break ;//��Ʊ��ģ��
            case 4 :
              Modify(l);break ;//�޸Ļ���Ϣ
			case 5:
				showtrain(l);break;//�Զ��庯����ʾ�г���Ϣ
            case 6 :
				SaveTrainInfo(l);SaveBookInfo(k);break ;//�������Ϣ/���涩Ʊ�˵���Ϣ
            case 0:
            	return 0;
        }
        printf("\nplease press any key to continue.......");
        getch();
        //getch()��
		//	����ͷ�ļ���conio.h
		//	������;���ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
		//	����ԭ�ͣ�int getch(void)
		//	����ֵ����ȡ���ַ�
    }
    
	return 0;
}