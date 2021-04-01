/**************************
*选择排序算法 
*选出最小值放在左边
*innerfire
****************************/


#include<stdio.h>//头文件 标准输入输出


void SelectSort(int *a, int n)//定义函数 两个参数 一个指针 一个int
 {
    for (int i = 0; i < n; i++)
    {
        int key = i;    //    临时变量用于存放数组最小值的位置
        for (int j = i + 1; j < n; j++) 
		{
            if (a[j] < a[key]) {    
                key = j;    //    记录数组最小值位置
            }
        }
            if (key != i)
            {
                int tmp = a[key];
				a[key] = a[i]; 
				a[i] = tmp;    //    交换最小值
            }
        
    }
}
int main() 
{
    int a[] = { 12,4,15,2,6,22,8,10,1,33,45,24,7 };//10个int数字
    int n = 10;
    SelectSort(a, n);//调用函数
    printf("排序好的数组为： ");
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);//输出
    printf("\n");
    return 0;
}