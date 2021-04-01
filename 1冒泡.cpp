/**************************
*冒泡排序算法 
*外层 内层 交换 循环
*innerfire
****************************/
#include<stdio.h>//头文件 标准输入输出

void bubbleSort(int *arr, int n) //定义函数 两个参数 一个指针 一个int
{
    for (int i = 0; i<n - 1; i++)//外层循环
        for (int j = 0; j < n - i - 1; j++)//内层循环 
        {
            //如果前面的数比后面大，进行交换
            if (arr[j] > arr[j + 1]) //地址传递
			{
                int temp = arr[j];// 定义临时变量
				arr[j] = arr[j + 1];//交换
				arr[j + 1] = temp;
            }
        }
}
int main() //主函数
{
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };//存放10个数字
    int n = 10;
    bubbleSort(arr, n);//调用函数
    printf("排序后的数组为：\n");//输出
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n"); 
    return 0;
}  


















