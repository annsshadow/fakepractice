#include <stdlib.h>

//����������a[]��b[]�ϲ���c[]��
void MemeryArray(int a[], int n, int b[], int m, int c[])
{
    int i, j, k;
    i = j = k = 0;

    while(i < n && j < m)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < n)
        c[k++] = a[i++];

    while(j < m)
        c[k++] = b[j++];
}

//���ж�����������a[first...mid]��a[mid...last]�ϲ���
void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while(i <= m && j <= n)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= n)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //�������
        mergesort(a, mid + 1, last, temp); //�ұ�����
        mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
    }
}

bool MergeSort(int a[], int n)
{
    int *p = new int[n];

    if(p == NULL)
        return false;

    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;
}