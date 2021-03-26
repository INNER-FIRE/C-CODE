#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ṹ��,��¼������Ϣ
typedef struct train_infor
{
    char number[10];//����
    char start[20];//ʼ����
    char end[20];//�յ�վ
    int year1,month1,day1,h1,m1;//��������ʱ��
    int year2,month2,day2,h2,m2;//��������ʱ��
}train;
int cnum=0;//��¼�ܹ��ж��ٸ��г���Ϣ��
train info[10000];//�ṹ�����͵����������������еĳ�����Ϣ��
train users[100][100];//��ά�������������û���Ϣ��ÿһ�п���������ʾһ���û��Ĺ�Ʊ��Ϣ
int vcs[100]={0};//������¼ÿһ�����Լ��˻���Ʊ������ʼȫΪ0��

//¼���Ʊ��Ϣ
void  create()
{
    int sum,i;
    printf("������Ҫ¼����г���Ϣ����:");
    scanf("%d",&sum);
    printf("���������복�� ʼ���� �յ�վ ����ʱ�䣨��/��/�� ʱ:�֣� ����ʱ�䣨��/��/�� ʱ:�֣���\n");
    for(i=cnum;i<cnum+sum;i++)//¼����Ϣ��cnum��ʼ��ԭ���Ǳ������Ա�Ƚ��в������Ӳ���������¼�����ݣ��������ǣ�ͬʱ�������Զ�ν���¼���������֮ǰ����Ϣ�¼�����ӣ�
        scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
    printf("¼��ɹ���\n");
    cnum+=sum;
    return ;
}

//��ʾ��Ʊ��Ϣ
void print()
{
    if(cnum==0)
    {
        printf("���г���Ϣ��\n");
        return ;
    }
    int i;
    printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
    for(i=0;i<cnum;i++)
        printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
    return ;
}

//��ѯ��Ʊ��Ϣ
void query()
{
    int i;
    printf("�������ѯ���Σ�");
    char ch[10];//��¼Ҫ��ѯ�ĳ���
    scanf("%s",ch);
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//�Ƚ����е��г���Ϣһֱ��������ĳ�����ͬ���ҵ���������ַ����ıȽ�Ҫ����strcmp()��������������Ϊ0
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
            return ;//�ҵ���ֱ�ӽ��������ٲ���
        }
    }
    printf("�޴��г���Ϣ��\n");//����ҵ�ǰ��ͽ����򲻻����е��˴����������е��˴�ֻ����û���ҵ���
    return ;
}
//�޸Ļ�Ʊ��Ϣ
void update()
{
    int i;
    printf("������Ҫ�޸ĵĳ��Σ�");
    char ch[10];//��¼Ҫ�޸ĵĳ���
    scanf("%s",ch);
    //�Ͳ�ѯһ�����ҵ����г����ڵ�λ��,Ȼ���������޸�
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//�Ƚ����е��г���Ϣһֱ��������ĳ�����ͬ���ҵ���������ַ����ıȽ�Ҫ����strcmp()��������������Ϊ0
        {
            printf("���г�ԭ��Ϣ��\n");
            printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",info[i].number,info[i].start,info[i].end,info[i].year1,info[i].month1,info[i].day1,info[i].h1,info[i].m1,info[i].year2,info[i].month2,info[i].day2,info[i].h2,info[i].m2);
            printf("�������µ����ݣ�\n");
            printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
            scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
            printf("�޸ĳɹ���\n");
            return ;//�޸ĺ�ֱ�ӽ��������ٽ���
        }
    }
    printf("�޴��г���Ϣ��\n");//����ҵ�ǰ��ͽ����򲻻����е��˴����������е��˴�ֻ����û���ҵ���
    return ;
}

//��ӻ�Ʊ��Ϣ
void insert()
{
    int i=cnum;
    printf("������������Ϣ��\n");
    printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
    scanf("%s %s %s %d/%d/%d %d:%d %d/%d/%d %d:%d",info[i].number,info[i].start,info[i].end,&info[i].year1,&info[i].month1,&info[i].day1,&info[i].h1,&info[i].m1,&info[i].year2,&info[i].month2,&info[i].day2,&info[i].h2,&info[i].m2);
    cnum++;//�г���Ϣ��������һ
    printf("����ɹ���\n");
    return ;
}

//ɾ����Ʊ��Ϣ
void dele()
{
    int i,vis=-1;
    printf("������Ҫɾ���ĳ��Σ�");
    char ch[10];//��¼Ҫɾ���ĳ���
    scanf("%s",ch);
    //�Ͳ�ѯһ�����ҵ����г����ڵ�λ��,Ȼ��������ɾ��
    for(i=0;i<cnum;i++)
    {
        if(strcmp(ch,info[i].number)==0)//�Ƚ����е��г���Ϣһֱ��������ĳ�����ͬ���ҵ���������ַ����ıȽ�Ҫ����strcmp()��������������Ϊ0
        {
            vis=i;//��Ҫɾ���ĳ��ε��±걣��������Ϊ��ߵ�ɾ����������
            break;//�ҵ���Ϳ��Խ���ѭ��
        }
    }
    if(vis==-1)//vis��ʼֵ��Ϊ-1��Ϊ�±겻���ڸ�ֵ������������Һ�û��˵��û���ҵ��ó������Կ���ֱ�ӽ���
    {
        printf("�޴��г���Ϣ��\n");
        return ;
    }
    else
    {
        for(i=vis;i<cnum-1;i++)//visΪҪɾ���г���Ϣ���±꣬Ҫ�����ɾ��ֻ�ðѺ�ߵ���Ϣ������ǰ���и��Ǽ��ɣ��˴�i<cnum-1��Ϊ�˱������Խ�磻
        {
            info[i]=info[i+1];
        }
        printf("ɾ���ɹ���\n");
        cnum--;//�г���Ϣ��������һ��
        return ;
    }
}

//����Ա�˵�
void admin_menu()
{
    printf("***************************************************************\n");
    printf("*              ��ӭ�����Ʊ��Ϣ����ϵͳ                     *\n");
    printf("***************************************************************\n");
    printf("*                 1��¼���Ʊ��Ϣ                           *\n");
    printf("*                 2����ʾ��Ʊ��Ϣ                           *\n");
    printf("*                 3����ѯ��Ʊ��Ϣ                           *\n");
    printf("*                 4���޸Ļ�Ʊ��Ϣ                           *\n");
    printf("*                 5����ӻ�Ʊ��Ϣ                           *\n");
    printf("*                 6��ɾ����Ʊ��Ϣ                           *\n");
    printf("*                 0���˳�                                     *\n");
    printf("***************************************************************\n");
}

//����Ա����
void  admin()
{
    admin_menu();
    int choose2;
    while(~scanf("%d",&choose2))//ѡ���Ӧ�Ĳ�����
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
                return ;//����0ֱ���˳���������
            default :
                printf("��ѡ����Ч������Ӧ���Ŷ��\n");
                break ;
        }
        admin_menu();//ÿ�β����������ٴδ�ӡ�˵���
    }
}

//��Ʊ
void buy(int no)
{
    int i;
    printf("��������Ҫ��Ʊ�ĳ���:\n");
    char che[10];
    scanf("%s",che);
    for(i=0;i<cnum;i++)
    {
        if(strcmp(che,info[i].number)==0)
        {
            users[no][vcs[no]]=info[i];
            vcs[no]++;//���û��Ĺ�Ʊ����һ��
            printf("��Ʊ�ɹ���\n");
            return ;
        }
    }
    printf("�޴��г���Ϣ��\n");
    return ;
}

//��Ʊ�����ѯ
void look_up(int no)
{
    if(cnum==0)
    {
        printf("�޳�����Ϣ�������Ա���г�����Ϣ¼�룡\n");
        return ;
    }
    char starts[20];
    char ends[20];
    int cnums=0,i;//��¼��ѯ���ĳ�������
    printf("�������ѯ����ʼ ��ֹ����(�ո����Ŷ��):\n");
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
        printf("�޴����䳵����Ϣ��\n");
        return ;
    }
    else
    {
        printf("------------------------\n");
        printf("|       �Ƿ�Ʊ       |\n");
        printf("------------------------\n");
        printf("|   1����  |   2����   |\n");
        printf("------------------------\n");
        int choose4;//��¼�û���ѡ��
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
             printf("��ѡ����Ч������Ӧ���Ŷ��\n");
             break ;
          }
          printf("------------------------\n");
          printf("|       �Ƿ�Ʊ       |\n");
          printf("------------------------\n");
          printf("|   1����  |   2����   |\n");
          printf("------------------------\n");
        }

    }
}

//��Ʊ
void refund(int no)
{
    int vis=-1,i;
    if(vcs[no]==0)
    {
        printf("�㻹��δ��ƱŶ��\n");
        return ;
    }
    else
    {
        printf("��Ĺ�Ʊ��Ϣ��\n");
        printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
        for(i=0;i<vcs[no];i++)
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",users[no][i].number,users[no][i].start,users[no][i].end,users[no][i].year1,users[no][i].month1,users[no][i].day1,users[no][i].h1,users[no][i].m1,users[no][i].year2,users[no][i].month2,users[no][i].day2,users[no][i].h2,users[no][i].m2);
        }
        printf("��������Ʊ����:");
        char cs[10];
        scanf("%s",cs);
        for(i=0;i<vcs[no];i++)
            {
                if(strcmp(cs,users[no][i].number)==0)//�Ƚ�������Ʊ���г���Ϣһֱ��������ĳ�����ͬ���ҵ���������ַ����ıȽ�Ҫ����strcmp()��������������Ϊ0
                {
                    vis=i;//��Ҫ��Ʊ�ĳ��ε��±걣��������Ϊ��ߵ�ɾ����������
                    break;//�ҵ���Ϳ��Խ���ѭ��
                }
            }
            if(vis==-1)//vis��ʼֵ��Ϊ-1��Ϊ�±겻���ڸ�ֵ������������Һ�û��˵��û���ҵ��ó������Կ���ֱ�ӽ���
            {
               printf("����δ������г���Ʊ��\n");
               return ;
            }
            else
            {
                for(i=vis;i<vcs[no]-1;i++)//visΪҪɾ���г���Ϣ���±꣬Ҫ�����ɾ��ֻ�ðѺ�ߵ���Ϣ������ǰ���и��Ǽ��ɣ��˴�i<vcs[no]-1��Ϊ�˱������Խ�磻
                {
                    users[no][i]=users[no][i+1];
                }
                printf("��Ʊ�ɹ���\n");
                vcs[no]--;//��Ʊ��������һ��
                return ;
            }
    }
}

//��ӡ��Ʊ��Ϣ
void out_print(int no)
{
    int i;
    if(vcs[no]==0)
    {
        printf("�޹�Ʊ��¼��\n");
        return ;
    }
    else
    {
        printf("����\tʼ����\t�յ�վ\t����ʱ��\t\t����ʱ��\n");
        for(i=0;i<vcs[no];i++)
        {
            printf("%s\t%s\t%s\t%d/%02d/%02d %02d:%02d\t%d/%02d/%02d %02d:%02d\n",users[no][i].number,users[no][i].start,users[no][i].end,users[no][i].year1,users[no][i].month1,users[no][i].day1,users[no][i].h1,users[no][i].m1,users[no][i].year2,users[no][i].month2,users[no][i].day2,users[no][i].h2,users[no][i].m2);
        }
    }
}
//�û��˵�
void user_menu()
{
    printf("***************************************************************\n");
    printf("*               ��ӭ�����Ʊ��Ʊϵͳ                        *\n");
    printf("***************************************************************\n");
    printf("*                 1����Ʊ�����ѯ                           *\n");
    printf("*                 2����ӡ��Ʊ��Ϣ                             *\n");
    printf("*                 3����Ʊ                                     *\n");
    printf("*                 0���˳�                                     *\n");
    printf("***************************************************************\n");
}

//�û�����
void user()
{
    int no;
    printf("����������û����룺");
    scanf("%d",&no);//��¼�û�����������Ӧ�ı����乺Ʊ��Ϣ
    user_menu();
    int choose3;
    while(~scanf("%d",&choose3))//��¼�û�ѡ��Ĳ�����
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
            return ;//����0ֱ���˳���������
        default :
            printf("��ѡ����Ч������Ӧ���Ŷ��\n");
            break ;
        }
        user_menu();
    }
}

int main()
{
    printf("��ʾ����������������ϸ��ո�ʽ������ΪӢ�ģ�\n");
    printf("-------------��ѡ�����-------------\n");
    printf("| 1���� �� Ա    |   2����  ��     |\n");
    printf("|           0����������            |\n");
    printf("------------------------------------\n");//����1��ʾ�������Ա���棬2�����û�����
    int choose1;
    while(~scanf("%d",&choose1))//��¼ѡ�����ţ��������
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
            printf("��ѡ����Ч������Ӧ���Ŷ��\n");
            break;
    }
        printf("-------------��ѡ�����-------------\n");
        printf("| 1���� �� Ա    |   2����  ��     |\n");
        printf("|           0����������            |\n");
        printf("------------------------------------\n");
    }
    return 0;
}
