void shellsort1(int a[], int n)
{
    int i, j, gap;

    for(gap = n / 2; gap > 0; gap /= 2)  //����
        for(i = 0; i < gap; i++)         //ֱ�Ӳ�������
        {
            for(j = i + gap; j < n; j += gap)
                if(a[j] < a[j - gap])
                {
                    int temp = a[j];
                    int k = j - gap;

                    while(k >= 0 && a[k] > temp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }

                    a[k + gap] = temp;
                }
        }
}

void shellsort2(int a[], int n)
{
    int j, gap;

    for(gap = n / 2; gap > 0; gap /= 2)
        for(j = gap; j < n; j++) //�������gap��Ԫ�ؿ�ʼ
            if(a[j] < a[j - gap]) //ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������
            {
                int temp = a[j];
                int k = j - gap;

                while(k >= 0 && a[k] > temp)
                {
                    a[k + gap] = a[k];
                    k -= gap;
                }

                a[k + gap] = temp;
            }
}

void shellsort3(int a[], int n)
{
    int i, j, gap;

    for(gap = n / 2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
                Swap(a[j], a[j + gap]);
}
