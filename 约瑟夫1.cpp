/**************************
*Լɪ�� ������ʵ��
innerfire
CSDN������ʦԭ��
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
����ѭ������
����ƪ���ݽṹ��ѭ�������ʵ�ֲ�����ѭ����������ͷ��㣬�����ǵĵ�������ͷ����ǷǱ��룬����Ҫ��ͷָ�룬��ͷ���ͷָ��ָ��ͷ���
��ͷ��㣬ͷָ��ָ��ͷ��㡣
��ѭ�������У������ͷ��� ��ôβ����ָ����ָ��ͷ����γɻ������û��ͷ��� ��ôβ����ָ����ָ���һ������γɻ���
����ͷ��㶼����Ҫ����Ҫ��������˼�룬���ָ��ӷ��������ǵ����⣬������Ƿ���Ҫͷ��㡣
num ΪԼɪ�򻷵Ľ�����
����Լɪ�򻷵Ľ�㣬����Լɪ�򻷣�ʹ��ѭ������ģ��
*/
int Create(Node** joseph,int num)
{
	if (joseph == NULL || num < 1)
	{
		return ERROR;
	}
	//����ͷ���
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
 
	//�ƶ���ָ�룬��ʼָ��ͷ���
	Node* p = head;
	//����Լɪ����,����β�巨��ÿ�δ����Ľ��ŵ�����β��
	for (size_t i = 1; i <= num; i++)
	{
		//�����½�㣬���Ҹ�ֵ
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = i;
		node->next = head;
 
		//����2����ɶ��
		//pָ������β��㣬p->next=node ���½������ӵ�����β����
		//p = node �ƶ�pָ������ʼ��ָ������β���
		p->next = node;
		p = node;
	}
	
	p->next = head->next;
	free(head);
	//Լɪ�򻷣�ѭ��������ͷָ��ָ�򻷵�һ�����
	*joseph = p->next;
	return OK;
}
int Length(Node* joseph)
{
	if (joseph == NULL)
	{
		return 0;
	}
	Node* target = joseph;//��ʼtargetָ���һ�����
	int length = 1;
	for (; target->next!=joseph; target = target->next)
	{
		length++;
	}
	return length;
}
/*
ģ��Լɪ����ɱ����
ÿ������3���˽�����ɱ��Ȼ�����һ�������¿�ʼ����������3���˽�����ɱ...
�����4�˸�������ɱ
1 2 3 4
����˳��:->3->2->4->1
n Ϊ ������ n������ɱ��Լɪ�� ���� �� ÿ������3������ɱ��
������Խ������ã�Ҳ����ÿ���� ��4���˽�����ɱ��
*/
int ShowKill(Node* joseph,int n)
{
	if (joseph == NULL)
	{
		return ERROR;
	}
	int num = Length(joseph);
	//skipΪɱ��n����Ҫ��Խ������
	int skip = n-1;
	Node* p = joseph;
	Node* begin = p;//beginָ��ʼ���ĵ�1����
	while (1)
	{
		begin = p;
		//�ҵ���ɱ�˵�ǰһ��λ��
		for (size_t i = 0; i < skip-1; i++)
		{
			p = p->next;
		}
 
		//���ʣ2����ʱ��������ɱ
		//temp == p->next ʱʣ�����2���ˣ�
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
 
 
		//ѭ���꣬p ָ����ɱǰ��һ����
		//p->next ������ɱ��ʵ���Ͼ��ǽ�p->next����ѭ�������иɵ�
		Node* kill = p->next;
		printf("-->%d", kill->data);
		//��kill�Ƴ����
		p->next = kill->next;
		free(kill);
		kill = NULL;
 
		//p�ƶ�������3���˵ĵ�1���˵�λ�� 
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
		printf("������Լɪ������(����0�˳�):");
		scanf("%d", &num);
		if (!num)
		{
			break;
		}
		printf("Լɪ������˳��:\n");
		joseph = NULL;
		Create(&joseph,num);
		ShowKill(joseph, 3);
	}
	return 0;
}
