//�ѵĲ���
//  �¼���i���  �丸���Ϊ(i - 1) / 2
void MinHeapFixup(int a[], int i)
{
    int j, temp;
    temp = a[i];
    j = (i - 1) / 2;      //�����

    while(j >= 0 && i != 0)
    {
        if(a[j] <= temp)
            break;

        a[i] = a[j];     //�ѽϴ���ӽ�������ƶ�,�滻�����ӽ��
        i = j;
        j = (i - 1) / 2;
    }

    a[i] = temp;
}

void MinHeapFixup(int a[], int i)
{
    for(int j = (i - 1) / 2; (j >= 0 && i != 0) && a[i] > a[j]; i = j, j = (i - 1) / 2)
        Swap(a[i], a[j]);
}

//����С���м����µ�����nNum
void MinHeapAddNumber(int a[], int n, int nNum)
{
    a[n] = nNum;
    MinHeapFixup(a, n);
}

//�ѵ�ɾ��
/*�����壬����ÿ�ζ�ֻ��ɾ����0�����ݡ�
Ϊ�˱����ؽ��ѣ�ʵ�ʵĲ����ǽ����һ�����ݵ�ֵ��������㣬Ȼ���ٴӸ���㿪ʼ����һ�δ������µĵ�����
����ʱ�������Ҷ��ӽ��������С�ģ���������������С���ӽ�㻹С˵������Ҫ�����ˣ���֮�����������������ٿ��Ǻ���Ľ�㡣
�൱�ڴӸ���㽫һ�����ݵġ��³������̡�*/

//  ��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;

    while(j < n)
    {
        if(j + 1 < n && a[j + 1] < a[j])  //�����Һ���������С��
            j++;

        if(a[j] >= temp)
            break;

        a[i] = a[j];     //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����
        i = j;
        j = 2 * i + 1;
    }

    a[i] = temp;
}
//����С����ɾ����
void MinHeapDeleteNumber(int a[], int n)
{
    Swap(a[0], a[n - 1]);
    MinHeapFixdown(a, 0, n - 1);
}

//�ѻ�����
//������С��
void MakeMinHeap(int a[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        MinHeapFixdown(a, i, n);
}

//������
/*���ȿ��Կ����ѽ���֮����е�0�������Ƕ�����С�����ݡ�
ȡ�����������ִ���¶ѵ�ɾ��������
�������е�0���������Ƕ�����С�����ݣ��ظ���������ֱ������ֻ��һ������ʱ��ֱ��ȡ��������ݡ�*/
void MinheapsortTodescendarray(int a[], int n)
{
    for(int i = n - 1; i >= 1; i--)
    {
        Swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
    }
}
//ע��ʹ����С��������ǵݼ����飬Ҫ�õ��������飬����ʹ�����ѡ�
