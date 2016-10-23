//冒泡排序1
void BubbleSort1(int a[], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 1; j < n - i; j++)
            if(a[j - 1] > a[j])
                Swap(a[j - 1], a[j]);
}

//冒泡排序2
void BubbleSort2(int a[], int n)
{
    int j, k;
    bool flag;
    k = n;
    flag = true;//如果有一趟没有交换,就说明排序已经完成了

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

//冒泡排序3
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
                flag = j;//从数组头部遍历到这个位置就可以了
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
