/**********************************
*��ָ��ʵ��Լɪ������
*
*
*********************************/
#include <stdio.h>
#include <conio.h>//getch()
#include <string.h>
#include <malloc.h>
#include <stdlib.h>//exit

#define LEN 21//����

#define OVER "exit"

typedef struct as Person;
//����������Ľṹ��
struct ps
{
	char name[LEN];
	int pwd;
	struct ps *next;
};
Person *head = NULL;//ͷָ���
Person *tail = NULL;//β
char choice;//�˵�

void InputPerson()
void ShowMenu()
void DisplayLink()//������Ϣ
void ResetPwd()//����
void CountAndQuit()

int num = 0;

void main()

{
	InputPerson();
	while (1)
	{
		ShowMenu();
		switch (choice)
		{
        case '1':
			DisplayLink()
				break;
		case '2':
			ResetPwd()
				break;
			case '3';
			CountAndQuit()
				break;

	}
	   }


}