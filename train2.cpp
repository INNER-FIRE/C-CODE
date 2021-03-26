#include <conio.h>
//conio是Console Input/Output（控制台输入输出）的简写，其中定义了通过控制台进行数据输入和数据输出的函数，主要是一些用户通过按键盘产生的对应操作，比如getch()函数等等。
#include <stdio.h>
//stdio 就是指 “standard input & output"（标准输入输出）,例如c语言中的 printf("%d",i); scanf("%d",&i);等函数
#include <stdlib.h>
//stdlib 头文件即standard library标准库头文件,如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()等等
#include <string.h>
//C语言标准库中一个常用的头文件，在使用到字符数组时需要使用。
//strlen求字符串长度
//strcmp比较2个字符串是否一样
//strcat字符串连接操作
//strcpy字符串拷贝操作
//strncat字符串连接操作(前n个字符)
//strncpy字符串拷贝操作(前n个字符)
//strchr查询字串
//strstr 查询子串
#include <dos.h>
#include "trainandman.h"

//#define HEADER1 " -------------------------------BOOK TICKET----------------------------------\n"
//#define HEADER2 " |  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
//#define HEADER3 " |----------|----------|----------|-----------|-----------|-----|------------|\n"
//#define FORMAT  " |%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
//#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum


int main()
{
	FILE*fp1,*fp2 ;//文件类型指针 
	Node *p,*r ;//火车信息链表的结点结构指针 
    char ch1,ch2 ;
    Link l ;//火车信息链表的结点结构指针
    bookLink k ;//订票人链表的结点结构指针 
    book *t,*h ;//订票人链表的结点结构指针 
    int sel ;
    l=(Node*)malloc(sizeof(Node));//动态内存分配，用于申请一块连续的指定大小的内存块区域
	//当无法知道内存具体位置的时候，想要绑定真正的内存空间，就需要用到动态的分配内存。
	//一般需和free函数配对使用
    l->next=NULL ;
    r=l ;
    k=(book*)malloc(sizeof(book));//强制类型装换 
    k->next=NULL ;
    h=k ;
    
	fp1=fopen("f:\\train.txt","ab+");/*打开存储车票信息的文件*/
	//打开文件，读文件到内存，返回文件信息结构指针    rb+ 读写打开一个二进制文件，只允许读写数据。 ab+ 读写打开一个二进制文件，允许读或在文件末追加数据。
    if((fp1==NULL))//文件没有打开成功 
    {
        printf("can't open the file!");
        return 0 ;
    }
    while(!feof(fp1))//测试文件流是否到结尾 //feof是C语言标准库函数，其原型在stdio.h中，其功能是检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0
    {
        p=(Node*)malloc(sizeof(Node));//为p动态开辟内存 
        if(fread(p,sizeof(Node),1,fp1)==1)/*从指定磁盘文件读取记录*/
        {
            p->next=NULL ;
            r->next=p ;/*构造链表*/
            r=p ;
        }
    }
    fclose(fp1);//关闭文件 
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
        system("CLS");//system函数需加头文件<stdlib.h>后方可调用。
        //system("CLS")可以实现清屏操作。
        menu();
        printf("\tplease choose (0~6):  ");
        scanf("%d",&sel);
        system("CLS"); 
    	if(sel==0)
        {
	    if(saveflag==1)//当退出时判断信息是否保存
           {
                getchar();
                //getchar有一个int型的返回值.当程序调用getchar时.
				//程序就等着用户按键.用户输入的字符被存放在键盘缓冲区中.
				//直到用户按回车为止(回车字符也放在缓冲区中).
				//当用户键入回车之后,getchar才开始从stdio流中每次读入一个字符.
				//getchar函数的返回值是用户输入的第一个字符的ASCII码,
				//如出错返回-1,且将用户输入的字符回显到屏幕.
				//如用户在按回车之前输入了不止一个字符,其他字符会保留在键盘缓存区中,
				//等待后续getchar调用读取.也就是说,后续的getchar调用不会等待用户按键,
				//而直接读取缓冲区中的字符,直到缓冲区中的字符读完为后,才等待用户按键.
                printf("\nthe file have been changed!do you want to save it(y/n)?\n");
                scanf("%c",&ch1);
                if(ch1=='y'||ch1=='Y')
                {
					SaveBookInfo(k);//保存订票人的信息
                    SaveTrainInfo(l);//保存火车信息
                }
            }
            printf("\nThank you!!You are welcome too\n");
            break ;//跳出永久循环 

        }
        switch(sel)//根据输入的sel值不同选择相应操作
        {
            case 1 :
              Traininfo(l);break ;//添加一个火车信息
            case 2 :
              searchtrain(l);break ;//查询火车信息
            case 3 :
              Bookticket(l,k);break ;//订票子模块
            case 4 :
              Modify(l);break ;//修改火车信息
			case 5:
				showtrain(l);break;//自定义函数显示列车信息
            case 6 :
				SaveTrainInfo(l);SaveBookInfo(k);break ;//保存火车信息/保存订票人的信息
            case 0:
            	return 0;
        }
        printf("\nplease press any key to continue.......");
        getch();
        //getch()：
		//	所在头文件：conio.h
		//	函数用途：从控制台读取一个字符，但不显示在屏幕上
		//	函数原型：int getch(void)
		//	返回值：读取的字符
    }
    
	return 0;
}