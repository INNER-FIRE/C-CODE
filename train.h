#ifndef _TRAINANDMAN_H_
#define _TRAINANDMAN_H_

/*����洢����Ϣ�Ľṹ��*/
struct train 
{
    char num[10];/*�г���*/
    char startcity[10];/*��������*/
    char reachcity[10];/*Ŀ�ĳ���*/
    char takeofftime[10];/*����ʱ��*/
    char receivetime[10];/*����ʱ��*/
    int  price;/*Ʊ��*/
    int  ticketnum ;/*Ʊ��*/
};

/*��Ʊ�˵���Ϣ*/
struct man 
{
    char num[10];/*ID*/
    char name[10];/*����*/
    int  bookNum ;/*����Ʊ��*/
};

/*�������Ϣ����Ľڵ�ṹ*/
typedef struct node //typedef�������µ�������NodeΪnode�ṹ�����͡�LinkΪnode�ṹ���ָ������ 
{
    struct train data ;/*����train�ṹ�����͵ı���data*/ 
    struct node * next ;//����ڵ�ָ����һ���ڵ��ָ��
}Node,*Link ;

/*���嶩Ʊ������Ľڵ�ṹ*/
typedef struct Man //typedef�������µ�������bookΪMan�ṹ�����͡�bookLinkΪMan�ṹ���ָ������
{
    struct man data ;
    struct Man *next ;
}book,*bookLink ;

extern int saveflag ;

void menu();/* ��ʼ����*/
void SaveTrainInfo(Link l);/*�������Ϣ*/
void SaveBookInfo(bookLink k);/*���涩Ʊ�˵���Ϣ*/
void Traininfo(Link linkhead);/*���һ������Ϣ*/
void searchtrain(Link l);/*��ѯ����Ϣ*/
void Bookticket(Link l,bookLink k);/*��Ʊ��ģ��*/
void Modify(Link l);/*�޸Ļ���Ϣ*/
void showtrain(Link l);/*�Զ��庯����ʾ�г���Ϣ*/
void SaveTrainInfo(Link l);/*�������Ϣ*/
void SaveBookInfo(bookLink k);/*���涩Ʊ�˵���Ϣ*/

/*��ӡ��Ʊ��Ϣ*/
void printheader(); /*��ʽ�������ͷ*/
void printdata(Node *q); /*��ʽ�������������*/

#endif
? 2021 GitHub, Inc.