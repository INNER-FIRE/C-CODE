#include<stdio.h>
//ð�������㷨
void bubbleSort(int *arr, int n) {
    for (int i = 0; i<n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            //���ǰ������Ⱥ���󣬽��н���
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; 
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
            }
        }
}
int main() {
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    printf("����������Ϊ��\n");
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n"); 
    return 0;
}