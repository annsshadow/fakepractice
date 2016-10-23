void Selectsort(int a[], int n)
{
    int i, j, nMinIndex;

    for(i = 0; i < n; i++)
    {
        nMinIndex = i; //����СԪ�ص�λ��

        for(j = i + 1; j < n; j++)
            if(a[j] < a[nMinIndex])
                nMinIndex = j;

        Swap(a[i], a[nMinIndex]); //�����Ԫ�طŵ��������Ŀ�ͷ
    }
}

inline void Swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

inline void Swap1(int &a, int &b)
{
    if(a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
