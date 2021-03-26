/**********************************
*用指针实现约瑟夫环问题
*
*
*********************************/
#include <stdio.h>
#include <conio.h>//getch()
#include <string.h>
#include <malloc.h>
#include <stdlib.h>//exit

#define LEN 21//人名

#define OVER "exit"

typedef struct as Person;
//人名和密码的结构体
struct ps
{
	char name[LEN];
	int pwd;
	struct ps *next;
};
Person *head = NULL;//头指向空
Person *tail = NULL;//尾
char choice;//菜单

void InputPerson()
void ShowMenu()
void DisplayLink()//链表信息
void ResetPwd()//密码
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