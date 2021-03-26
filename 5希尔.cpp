#include<stdio.h>
//    进行插入排序
//    初始时从dk开始增长，每次比较步长为dk
void Insrtsort(int *a, int n,int dk)
 {
    for (int i = dk; i < n; ++i) {
        int j = i - dk;
        if (a[i] < a[j]) {    //    比较前后数字大小
            int tmp = a[i];        //    作为临时存储    
            a[i] = a[j];
            while (a[j] > tmp) {    //    寻找tmp的插入位置
                a[j+dk] = a[j];
                j -= dk;
            }
            a[j+dk] = tmp;        //    插入tmp
        }
    }
}

void ShellSort(int *a, int n) 
{
    int dk = n / 2;        //    设置初始dk
    while (dk >= 1) {
        Insrtsort(a, n, dk);
        dk /= 2;
    }
}

int main()
{
    int a[] = { 5,12,35,42,11,2,9,41,26,18,4 };
    int n = sizeof(a) / sizeof(int);
    ShellSort(a, n);
    printf("排序好的数组为：");
    for (int j = 0; j < n; j++) {
        printf("%d ", a [j]);
    }
    return 0;
}