/**************************
*���������㷨 
*�ֳ�����  ���� 
*�ֱ�����
****************************/
#include<stdio.h>//ͷ�ļ� ��׼�������

void swap(int *x, int *y) //���彻������ ��ָ�봫��
{
    int tmp = *x;//������ʱ����
    *x = *y;
    *y = tmp;
}

//���η�������ֳ�����
int patition(int *a, int left,int right) 
{
    int j = left;    //������������
    int i = j - 1;    
    int key = a[right];    
    //�����ұ������飬��С�ڵ��ڻ�׼Ԫ�صķŵ���ߣ����ڻ�׼Ԫ�صķŵ��ұ�
    for (; j < right; ++j) {
        if (a[j] <= key)
            swap(&a[j], &a[++i]);
    }
    //�ѻ�׼Ԫ�طŵ��м�
    swap(&a[right], &a[++i]);
    //���������м�λ��
    return i;
}
//��������
void quickSort(int *a,int left,int right)//���庯�� �������� һ��ָ��
 {
    if (left>=right)//
        return;
    int mid = patition(a,left,right);//�м�ֵ
    quickSort(a, left, mid - 1);//�����
    quickSort(a, mid + 1, right);//���ұ�
}
int main() //���������
{
    int a[] = { 10,6,5,7,12,8,1,3,11,4,2,9,16,13,15,14 };
    int n = 16;
    quickSort(a, 0,n-1);//���ú���
    printf("����õ�����Ϊ��");
    for (int l = 0; l < n; l++)//ѭ����� 
	{
        printf("%d ", a[l]);
    }
    printf("\n");
    return 0;
}