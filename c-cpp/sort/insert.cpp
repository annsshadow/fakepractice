void Insertsort1(int a[], int n)//��С����
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        //Ϊa[i]��ǰ���a[0...i-1]������������һ�����ʵ�λ��
        for (j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                break;

        //���ҵ���һ�����ʵ�λ��
        if (j != i - 1)
        {
            //����a[i]������������
            int temp = a[i];
            for (k = i - 1; k > j; k--)
                a[k + 1] = a[k];
            //��a[i]�ŵ���ȷλ����
            a[k + 1] = temp;
        }
    }
}

void Insertsort2(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1])
        {
            int temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
                a[j + 1] = a[j];
            a[j + 1] = temp;
        }
}
/*�����������ݺ������������ϲ���
��ÿ��a[i]�Ⱥ�ǰ��һ������a[i-1]�Ƚϣ����a[i] > a[i-1]˵��a[0��i]Ҳ������ģ����������
�������j=i-1,temp=a[i]��Ȼ��һ�߽�����a[j]����ƶ�һ����ǰ��������������a[j]<a[i]ʱֹͣ����temp�ŵ�a[j + 1]����*/


void Insertsort3(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
            Swap(a[j], a[j + 1]);
}
/*�ٶԽ�a[j]���뵽ǰ��a[0��j-1]�������������õķ������и�д�������ݽ����������ݺ��ơ�
���a[j]ǰһ������a[j-1] > a[j]���ͽ���a[j]��a[j-1]����j--ֱ��a[j-1] <= a[j]��*/
