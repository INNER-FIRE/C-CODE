/**************************
*ѡ�������㷨 
*ѡ����Сֵ�������
*innerfire
****************************/


#include<stdio.h>//ͷ�ļ� ��׼�������


void SelectSort(int *a, int n)//���庯�� �������� һ��ָ�� һ��int
 {
    for (int i = 0; i < n; i++)
    {
        int key = i;    //    ��ʱ�������ڴ��������Сֵ��λ��
        for (int j = i + 1; j < n; j++) 
		{
            if (a[j] < a[key]) {    
                key = j;    //    ��¼������Сֵλ��
            }
        }
            if (key != i)
            {
                int tmp = a[key];
				a[key] = a[i]; 
				a[i] = tmp;    //    ������Сֵ
            }
        
    }
}
int main() 
{
    int a[] = { 12,4,15,2,6,22,8,10,1,33,45,24,7 };//10��int����
    int n = 10;
    SelectSort(a, n);//���ú���
    printf("����õ�����Ϊ�� ");
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);//���
    printf("\n");
    return 0;
}