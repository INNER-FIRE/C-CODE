#include<stdio.h>
//    ���в�������
//    ��ʼʱ��dk��ʼ������ÿ�αȽϲ���Ϊdk
void Insrtsort(int *a, int n,int dk)
 {
    for (int i = dk; i < n; ++i) {
        int j = i - dk;
        if (a[i] < a[j]) {    //    �Ƚ�ǰ�����ִ�С
            int tmp = a[i];        //    ��Ϊ��ʱ�洢    
            a[i] = a[j];
            while (a[j] > tmp) {    //    Ѱ��tmp�Ĳ���λ��
                a[j+dk] = a[j];
                j -= dk;
            }
            a[j+dk] = tmp;        //    ����tmp
        }
    }
}

void ShellSort(int *a, int n) 
{
    int dk = n / 2;        //    ���ó�ʼdk
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
    printf("����õ�����Ϊ��");
    for (int j = 0; j < n; j++) {
        printf("%d ", a [j]);
    }
    return 0;
}