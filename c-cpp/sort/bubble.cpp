//ð������1
void BubbleSort1(int a[], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 1; j < n - i; j++)
            if(a[j - 1] > a[j])
                Swap(a[j - 1], a[j]);
}

//ð������2
void BubbleSort2(int a[], int n)
{
    int j, k;
    bool flag;
    k = n;
    flag = true;//�����һ��û�н���,��˵�������Ѿ������

    while(flag)
    {
        flag = false;

        for(j = 1; j < k; j++)
            if(a[j - 1] > a[j])
            {
                Swap(a[j - 1], a[j]);
                flag = true;
            }

        k--;
    }
}

//ð������3
void BubbleSort3(int a[], int n)
{
    int j, k;
    int flag;
    flag = n;

    while(flag > o)
    {
        k = flag;
        flag = 0;

        for(j = 1; j < k; j++)
            if(a[j - 1] > a[j])
            {
                Swap(a[j - 1], a[j]);
                flag = j;//������ͷ�����������λ�þͿ�����
            }
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
