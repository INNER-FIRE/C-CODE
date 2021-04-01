/**************************
*快速排序算法 
*分成两份  交换 
*分别排序
****************************/
#include<stdio.h>//头文件 标准输入输出

void swap(int *x, int *y) //定义交换函数 用指针传递
{
    int tmp = *x;//定义临时变量
    *x = *y;
    *y = tmp;
}

//分治法把数组分成两份
int patition(int *a, int left,int right) 
{
    int j = left;    //用来遍历数组
    int i = j - 1;    
    int key = a[right];    
    //从左到右遍历数组，把小于等于基准元素的放到左边，大于基准元素的放到右边
    for (; j < right; ++j) {
        if (a[j] <= key)
            swap(&a[j], &a[++i]);
    }
    //把基准元素放到中间
    swap(&a[right], &a[++i]);
    //返回数组中间位置
    return i;
}
//快速排序
void quickSort(int *a,int left,int right)//定义函数 三个参数 一个指针
 {
    if (left>=right)//
        return;
    int mid = patition(a,left,right);//中间值
    quickSort(a, left, mid - 1);//排左边
    quickSort(a, mid + 1, right);//排右边
}
int main() //主函数入口
{
    int a[] = { 10,6,5,7,12,8,1,3,11,4,2,9,16,13,15,14 };
    int n = 16;
    quickSort(a, 0,n-1);//调用函数
    printf("排序好的数组为：");
    for (int l = 0; l < n; l++)//循环输出 
	{
        printf("%d ", a[l]);
    }
    printf("\n");
    return 0;
}