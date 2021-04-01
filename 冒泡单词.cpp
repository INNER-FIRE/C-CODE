/**************************
*冒泡排序 
*单词按a-z排序
*innerfire
****************************/
#include <stdio.h>
#include <string.h>

void sort_length(char (*p)[11], int n);    //使用数组指针指向二维数组 

int main()
{
    char word[21][11];						//不超过20， 不超过10，  要多开一个存放结束符 
    char str[11];
    int i, j, n;

    i = 0; n  = 0;
    while (1)
    {
        scanf("%s", str);
        if (str[0] == '#')						//不能写成str == '#'   str是字符串的首地址 
            break;
        strcpy(word[i], str);
        i++;
        n++;								//n记录字符串的个数 
    }
    sort_length(word, n);

    return 0;
}
void sort_length(char (*p)[11], int n)//冒泡排序
{
    int i, j;
    char temp[11];

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strlen(p[j]) > strlen(p[j + 1]))
            {
                strcpy(temp, p[j]);
                strcpy(p[j], p[j + 1]);
                strcpy(p[j + 1], temp);
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%s ", p[i]);
}
