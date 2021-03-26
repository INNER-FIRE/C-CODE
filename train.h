#ifndef _TRAINANDMAN_H_
#define _TRAINANDMAN_H_

/*定义存储火车信息的结构体*/
struct train 
{
    char num[10];/*列车号*/
    char startcity[10];/*出发城市*/
    char reachcity[10];/*目的城市*/
    char takeofftime[10];/*发车时间*/
    char receivetime[10];/*到达时间*/
    int  price;/*票价*/
    int  ticketnum ;/*票数*/
};

/*订票人的信息*/
struct man 
{
    char num[10];/*ID*/
    char name[10];/*姓名*/
    int  bookNum ;/*订的票数*/
};

/*定义火车信息链表的节点结构*/
typedef struct node //typedef声明了新的类型名Node为node结构体类型、Link为node结构体的指针类型 
{
    struct train data ;/*声明train结构体类型的变量data*/ 
    struct node * next ;//链表节点指向下一个节点的指针
}Node,*Link ;

/*定义订票人链表的节点结构*/
typedef struct Man //typedef声明了新的类型名book为Man结构体类型、bookLink为Man结构体的指针类型
{
    struct man data ;
    struct Man *next ;
}book,*bookLink ;

extern int saveflag ;

void menu();/* 初始界面*/
void SaveTrainInfo(Link l);/*保存火车信息*/
void SaveBookInfo(bookLink k);/*保存订票人的信息*/
void Traininfo(Link linkhead);/*添加一个火车信息*/
void searchtrain(Link l);/*查询火车信息*/
void Bookticket(Link l,bookLink k);/*订票子模块*/
void Modify(Link l);/*修改火车信息*/
void showtrain(Link l);/*自定义函数显示列车信息*/
void SaveTrainInfo(Link l);/*保存火车信息*/
void SaveBookInfo(bookLink k);/*保存订票人的信息*/

/*打印火车票信息*/
void printheader(); /*格式化输出表头*/
void printdata(Node *q); /*格式化输出表中数据*/

#endif
? 2021 GitHub, Inc.