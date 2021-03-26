#include<stdio.h>

void SelectSort(int *a, int n)
 {
    for (int i = 0; i < n; i++)
    {
        int key = i;    //    临时变量用于存放数组最小值的位置
        for (int j = i + 1; j < n; j++) {
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
    int a[] = { 12,4,15,2,6,22,8,10,1,33,45,24,7 };
    int n = sizeof(a) / sizeof(int);
    SelectSort(a, n);
    printf("排序好的数组为： ");
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);
    printf("\n");
    return 0;
}