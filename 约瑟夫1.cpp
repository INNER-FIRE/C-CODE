/**************************
*约瑟夫 用链表实现
innerfire
CSDN李四老师原创
*
****************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
 
typedef struct Node
{
	int data;
	struct Node* next;
} Node;
/*
创建循环链表
在上篇数据结构—循环链表的实现博客中循环链表中有头结点，在我们的单链表中头结点是非必须，必须要有头指针，有头结点头指针指向头结点
无头结点，头指针指向头结点。
在循环链表中，如果有头结点 那么尾结点的指针域指向头结点形成环，如果没有头结点 那么尾结点的指针域指向第一个结点形成环。
有无头结点都不重要，重要的是这种思想，那种更加方便解决我们的问题，视情况是否需要头结点。
num 为约瑟夫环的结点个数
创建约瑟夫环的结点，构成约瑟夫环，使用循环链表模拟
*/
int Create(Node** joseph,int num)
{
	if (joseph == NULL || num < 1)
	{
		return ERROR;
	}
	//创建头结点
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
 
	//移动的指针，开始指向头结点
	Node* p = head;
	//创建约瑟夫结点,采用尾插法，每次创建的结点放到链表尾部
	for (size_t i = 1; i <= num; i++)
	{
		//创建新结点，并且赋值
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = i;
		node->next = head;
 
		//下面2步干啥？
		//p指向链表尾结点，p->next=node 将新建结点添加到链表尾部。
		//p = node 移动p指针让其始终指向链表尾结点
		p->next = node;
		p = node;
	}
	
	p->next = head->next;
	free(head);
	//约瑟夫环，循环链表中头指针指向环第一个结点
	*joseph = p->next;
	return OK;
}
int Length(Node* joseph)
{
	if (joseph == NULL)
	{
		return 0;
	}
	Node* target = joseph;//开始target指向第一个结点
	int length = 1;
	for (; target->next!=joseph; target = target->next)
	{
		length++;
	}
	return length;
}
/*
模拟约瑟夫自杀问题
每数到第3个人进行自杀，然后从下一个人重新开始数，数到第3个人进行自杀...
如果是4人个进行自杀
1 2 3 4
死亡顺序:->3->2->4->1
n 为 数到第 n个人自杀，约瑟夫 问题 是 每数到第3个人自杀。
这里可以进行设置，也可以每数到 第4个人进行自杀。
*/
int ShowKill(Node* joseph,int n)
{
	if (joseph == NULL)
	{
		return ERROR;
	}
	int num = Length(joseph);
	//skip为杀第n个人要跨越的人数
	int skip = n-1;
	Node* p = joseph;
	Node* begin = p;//begin指向开始数的第1个人
	while (1)
	{
		begin = p;
		//找到自杀人的前一个位置
		for (size_t i = 0; i < skip-1; i++)
		{
			p = p->next;
		}
 
		//最后剩2个人时，依次自杀
		//temp == p->next 时剩下最后2个人！
		if (begin == p->next)
		{
			printf("->%d", begin->data);
			printf("->%d", begin->next->data);
			free(begin);
			free(p);
			begin = NULL;
			p = NULL;
			break;
		}
 
 
		//循环完，p 指向自杀前面一个人
		//p->next 进行自杀，实质上就是将p->next结点从循环链表中干掉
		Node* kill = p->next;
		printf("-->%d", kill->data);
		//将kill移除结点
		p->next = kill->next;
		free(kill);
		kill = NULL;
 
		//p移动到后面3个人的第1个人的位置 
		p = p->next;
		
	}
	printf("\n");
	return OK;
}
 
int main(int argc, char *argv[])
{
	Node* joseph = NULL;
	int num = 1;
 
	while (num)
	{
		printf("请输入约瑟夫环人数(输入0退出):");
		scanf("%d", &num);
		if (!num)
		{
			break;
		}
		printf("约瑟夫环死亡顺序:\n");
		joseph = NULL;
		Create(&joseph,num);
		ShowKill(joseph, 3);
	}
	return 0;
}
