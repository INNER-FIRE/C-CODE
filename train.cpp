#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体,记录车次信息
typedef struct train_infor
{
    char number[10];//车次
    char start[20];//始发地
    char end[20];//终点站
    int year1,month1,day1,h1,m1;//发车日期时间
    int year2,month2,day2,h2,m2;//到达日期时间
}train;
int cnum=0;//记录总共有多少个列车信息；
train info[10000];//结构体类型的数组用来保存所有的车次信息；
train users[100][100];//二维数组用来保存用户信息，每一行可以用来表示一个用户的购票信息
int vcs[100]={0};//用来记录每一个人自己账户的票数，初始全为0；

//录入火车票信息
void  create()
{
    int sum,i;
    printf("请输入要录入的列车信息条数:");
    scanf("%d",&sum);
    printf("请依次输入车次 始发地 终点站 发车时间（年/月/日 时:分） 到达时间（年/月/日 时:分）；\n");
    for(i=cnum;i<cnum+sum;i++)//录入信息从cnum开始的原因是避免管理员先进行插入或添加操作后再来录入数据，发生覆盖；同时这样可以多次进行录入操作（在之前的信息下继续添加）
        scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
    printf("录入成功！\n");
    cnum+=sum;
    return ;
}

//显示火车票信息
void print()
{
    if(cnum==0)
    {
        printf("无列车信息！\n");
        return ;
    }
    int i;
    printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
    for(i=0;i<cnum;i++)
        printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
    return ;
}

//查询火车票信息
void query()
{
    int i;
    printf("请输入查询车次：");
    char ch[10];//记录要查询的车次
    scanf("%s",ch);
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//比较所有的列车信息一直到和输入的车次相同则找到并输出，字符串的比较要是用strcmp()函数；如果相等则为0
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
            return ;//找到后直接结束无需再查找
        }
    }
    printf("无此列车信息！\n");//如果找到前面就结束则不会运行到此处；所以运行到此处只能是没有找到；
    return ;
}
//修改火车票信息
void update()
{
    int i;
    printf("请输入要修改的车次：");
    char ch[10];//记录要修改的车次
    scanf("%s",ch);
    //和查询一样先找到该列车所在的位置,然后对其进行修改
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//比较所有的列车信息一直到和输入的车次相同则找到并输出，字符串的比较要是用strcmp()函数；如果相等则为0
        {
            printf("该列车原信息：\n");
            printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
            printf("请输入新的数据：\n");
            printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
            scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
            printf("修改成功！\n");
            return ;//修改后直接结束无需再进行
        }
    }
    printf("无此列车信息！\n");//如果找到前面就结束则不会运行到此处；所以运行到此处只能是没有找到；
    return ;
}

//添加火车票信息
void insert()
{
    int i=cnum;
    printf("请输入插入的信息：\n");
    printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
    scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
    cnum++;//列车信息总条数加一
    printf("插入成功！\n");
    return ;
}

//删除火车票信息
void dele()
{
    int i,vis=-1;
    printf("请输入要删除的车次：");
    char ch[10];//记录要删除的车次
    scanf("%s",ch);
    //和查询一样先找到该列车所在的位置,然后对其进行删除
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//比较所有的列车信息一直到和输入的车次相同则找到并输出，字符串的比较要是用strcmp()函数；如果相等则为0
        {
            vis=i;//将要删除的车次的下标保存下来，为后边的删除操作服务；
            break;//找到后就可以结束循环
        }
    }
    if(vis==-1)//vis初始值设为-1因为下标不存在负值，如果经过查找后还没变说明没有找到该车次所以可以直接结束
    {
        printf("无此列车信息！\n");
        return ;
    }
    else
    {
        for(i=vis;i<cnum-1;i++)//vis为要删除列车信息的下标，要想把它删除只用把后边的信息依次往前进行覆盖即可；此处i<cnum-1是为了避免最后越界；
        {
            info[i]=info[i+1];
        }
        printf("删除成功！\n");
        cnum--;//列车信息总条数减一；
        return ;
    }
}

//管理员菜单
void admin_menu()
{
    printf("***************************************************************\n");
    printf("*              欢迎进入火车票信息管理系统                     *\n");
    printf("***************************************************************\n");
    printf("*                 1、录入火车票信息                           *\n");
    printf("*                 2、显示火车票信息                           *\n");
    printf("*                 3、查询火车票信息                           *\n");
    printf("*                 4、修改火车票信息                           *\n");
    printf("*                 5、添加火车票信息                           *\n");
    printf("*                 6、删除火车票信息                           *\n");
    printf("*                 0、退出                                     *\n");
    printf("***************************************************************\n");
}

//管理员界面
void  admin()
{
    admin_menu();
    int choose2;
    while(~scanf("%d",&choose2))//选择对应的操作；
    {
        switch (choose2)
        {
            case 1:
                create();
                break;
            case 2:
                print();
                break;
            case 3:
                query();
                break;
            case 4:
                update();
                break;
            case 5:
                insert();
                break;
            case 6:
                dele();
                break;
            case 0:
                return ;//输入0直接退出整个函数
            default :
                printf("请选择有效操作对应编号哦！\n");
                break ;
        }
        admin_menu();//每次操作结束后再次打印菜单栏
    }
}

//买票
void buy(int no)
{
    int i;
    printf("请输入你要购票的车次:\n");
    char che[10];
    scanf("%s",che);
    for(i=0;i<cnum;i++)
    {
        if(strcmp(che,info[i].number)==0)
        {
            users[no][vcs[no]]=info[i];
            vcs[no]++;//该用户的购票数加一；
            printf("购票成功！\n");
            return ;
        }
    }
    printf("无此列车信息！\n");
    return ;
}

//火车票区间查询
void look_up(int no)
{
    if(cnum==0)
    {
        printf("无车次信息，请管理员进行车次信息录入！\n");
        return ;
    }
    char starts[20];
    char ends[20];
    int cnums=0,i;//记录查询到的车次条数
    printf("请输入查询的起始 终止区间(空格隔开哦！):\n");
    scanf("%s %s",starts,ends);
    for(i=0;i<cnum;i++)
    {
        if(strcmp(starts,info[i].start)==0&&strcmp(ends,info[i].end)==0)
            {
                printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
                cnums++;
            }
    }
    if(cnums==0)
    {
        printf("无此区间车次信息！\n");
        return ;
    }
    else
    {
        printf("------------------------\n");
        printf("|       是否购票       |\n");
        printf("------------------------\n");
        printf("|   1、是  |   2、否   |\n");
        printf("------------------------\n");
        int choose4;//记录用户的选择
        while(~scanf("%d",&choose4))
        {
          switch(choose4)
          {
           case 1:
             buy(no);
             break;
           case 2:
             return ;
           default :
             printf("请选择有效操作对应编号哦！\n");
             break ;
          }
          printf("------------------------\n");
          printf("|       是否购票       |\n");
          printf("------------------------\n");
          printf("|   1、是  |   2、否   |\n");
          printf("------------------------\n");
        }

    }
}

//退票
void refund(int no)
{
    int vis=-1,i;
    if(vcs[no]==0)
    {
        printf("你还尚未购票哦！\n");
        return ;
    }
    else
    {
        printf("你的购票信息：\n");
        printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
        for(i=0;i<vcs[no];i++)
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",users[no][i].number,users[no][i].start,users[no][i].end,users[no][i].year1,users[no][i].month1,users[no][i].day1,users[no][i].h1,users[no][i].m1,users[no][i].year2,users[no][i].month2,users[no][i].day2,users[no][i].h2,users[no][i].m2);
        }
        printf("请输入退票车次:");
        char cs[10];
        scanf("%s",cs);
        for(i=0;i<vcs[no];i++)
            {
                if(strcmp(cs,users[no][i].number)==0)//比较你所购票的列车信息一直到和输入的车次相同则找到并输出，字符串的比较要是用strcmp()函数；如果相等则为0
                {
                    vis=i;//将要退票的车次的下标保存下来，为后边的删除操作服务；
                    break;//找到后就可以结束循环
                }
            }
            if(vis==-1)//vis初始值设为-1因为下标不存在负值，如果经过查找后还没变说明没有找到该车次所以可以直接结束
            {
               printf("你尚未购买此列车车票！\n");
               return ;
            }
            else
            {
                for(i=vis;i<vcs[no]-1;i++)//vis为要删除列车信息的下标，要想把它删除只用把后边的信息依次往前进行覆盖即可；此处i<vcs[no]-1是为了避免最后越界；
                {
                    users[no][i]=users[no][i+1];
                }
                printf("退票成功！\n");
                vcs[no]--;//购票总条数减一；
                return ;
            }
    }
}

//打印购票信息
void out_print(int no)
{
    int i;
    if(vcs[no]==0)
    {
        printf("无购票记录！\n");
        return ;
    }
    else
    {
        printf("车次\t始发地\t终点站\t发车时间\t\t到达时间\n");
        for(i=0;i<vcs[no];i++)
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",users[no][i].number,users[no][i].start,users[no][i].end,users[no][i].year1,users[no][i].month1,users[no][i].day1,users[no][i].h1,users[no][i].m1,users[no][i].year2,users[no][i].month2,users[no][i].day2,users[no][i].h2,users[no][i].m2);
        }
    }
}
//用户菜单
void user_menu()
{
    printf("***************************************************************\n");
    printf("*               欢迎进入火车票售票系统                        *\n");
    printf("***************************************************************\n");
    printf("*                 1、火车票区间查询                           *\n");
    printf("*                 2、打印购票信息                             *\n");
    printf("*                 3、退票                                     *\n");
    printf("*                 0、退出                                     *\n");
    printf("***************************************************************\n");
}

//用户界面
void user()
{
    int no;
    printf("请输入你的用户编码：");
    scanf("%d",&no);//记录用户编码用来对应的保存其购票信息
    user_menu();
    int choose3;
    while(~scanf("%d",&choose3))//记录用户选择的操作；
    {
        switch(choose3)
        {
        case 1:
            look_up(no);
            break;
        case 2:
            out_print(no);
            break;
        case 3:
            refund(no);
            break;
        case 0:
            return ;//输入0直接退出整个函数
        default :
            printf("请选择有效操作对应编号哦！\n");
            break ;
        }
        user_menu();
    }
}

int main()
{
    printf("提示：整个输入过程请严格按照格式，标点均为英文！\n");
    printf("-------------请选择身份-------------\n");
    printf("| 1、管 理 员    |   2、用  户     |\n");
    printf("|           0、结束程序            |\n");
    printf("------------------------------------\n");//输入1表示进入管理员界面，2进入用户界面
    int choose1;
    while(~scanf("%d",&choose1))//记录选择的序号，多组测试
    {
    if(choose1==0)
            break;
    switch (choose1)
    {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default :
            printf("请选择有效操作对应编号哦！\n");
            break;
    }
        printf("-------------请选择身份-------------\n");
        printf("| 1、管 理 员    |   2、用  户     |\n");
        printf("|           0、结束程序            |\n");
        printf("------------------------------------\n");
    }
    return 0;
}
