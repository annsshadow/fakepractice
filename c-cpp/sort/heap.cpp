//堆的插入
//  新加入i结点  其父结点为(i - 1) / 2
void MinHeapFixup(int a[], int i)
{
    int j, temp;
    temp = a[i];
    j = (i - 1) / 2;      //父结点

    while(j >= 0 && i != 0)
    {
        if(a[j] <= temp)
            break;

        a[i] = a[j];     //把较大的子结点往下移动,替换它的子结点
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

//在最小堆中加入新的数据nNum
void MinHeapAddNumber(int a[], int n, int nNum)
{
    a[n] = nNum;
    MinHeapFixup(a, n);
}

//堆的删除
/*按定义，堆中每次都只能删除第0个数据。
为了便于重建堆，实际的操作是将最后一个数据的值赋给根结点，然后再从根结点开始进行一次从上向下的调整。
调整时先在左右儿子结点中找最小的，如果父结点比这个最小的子结点还小说明不需要调整了，反之将父结点和它交换后再考虑后面的结点。
相当于从根结点将一个数据的“下沉”过程。*/

//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;

    while(j < n)
    {
        if(j + 1 < n && a[j + 1] < a[j])  //在左右孩子中找最小的
            j++;

        if(a[j] >= temp)
            break;

        a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点
        i = j;
        j = 2 * i + 1;
    }

    a[i] = temp;
}
//在最小堆中删除数
void MinHeapDeleteNumber(int a[], int n)
{
    Swap(a[0], a[n - 1]);
    MinHeapFixdown(a, 0, n - 1);
}

//堆化数组
//建立最小堆
void MakeMinHeap(int a[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        MinHeapFixdown(a, i, n);
}

//堆排序
/*首先可以看到堆建好之后堆中第0个数据是堆中最小的数据。
取出这个数据再执行下堆的删除操作。
这样堆中第0个数据又是堆中最小的数据，重复上述步骤直至堆中只有一个数据时就直接取出这个数据。*/
void MinheapsortTodescendarray(int a[], int n)
{
    for(int i = n - 1; i >= 1; i--)
    {
        Swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
    }
}
//注意使用最小堆排序后是递减数组，要得到递增数组，可以使用最大堆。
