/**************************
*ð�������㷨 
*��� �ڲ� ���� ѭ��
*innerfire
****************************/
#include<stdio.h>//ͷ�ļ� ��׼�������

void bubbleSort(int *arr, int n) //���庯�� �������� һ��ָ�� һ��int
{
    for (int i = 0; i<n - 1; i++)//���ѭ��
        for (int j = 0; j < n - i - 1; j++)//�ڲ�ѭ�� 
        {
            //���ǰ������Ⱥ���󣬽��н���
            if (arr[j] > arr[j + 1]) //��ַ����
			{
                int temp = arr[j];// ������ʱ����
				arr[j] = arr[j + 1];//����
				arr[j + 1] = temp;
            }
        }
}
int main() //������
{
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };//���10������
    int n = 10;
    bubbleSort(arr, n);//���ú���
    printf("����������Ϊ��\n");//���
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n"); 
    return 0;
}  


















