# include <iostream>
# include <limits.h>

using namespace std;

template <class T>

int getArrayLen(T& array)
{
    return (sizeof(array) / sizeof(array[0]));
}

int singleNumber(int* array, int arrLen)
{
    int ones = 0;
    int twos = 0;
    int* current = NULL;

    for(int i = 0; arrLen > i; i++)
    {
        current = array + i;
        //cout << *current << endl;
        ones = (ones ^ *current) & ~twos;
        twos = (twos ^ *current) & ~ones;
    }
    return ones;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int eggDrop(int n, int k)
{
    /* eggFloor[i][j] 表示对于 i个鸡蛋 j 层楼，需要的最少测试次数 */
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;
    // 初始化
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    //只有一个鸡蛋，没得优化，需要j次
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // 最优子结构的递推
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
    return eggFloor[n][k];
}

/* 测试*/
int main()
{
    int n = 2, k = 36;
    int testArr[] = {1, 2, 3, 4, 4, 4, 2, 2, 1, 1};
    cout << "\nMinimum number of trials in worst case with" << n << "eggs and " << k << " floors is " << eggDrop(n, k) << endl;
    int arrLen;
    arrLen = getArrayLen(testArr);
    cout << "arrLen" << arrLen << endl;
    cout << "singleNum:" << singleNumber(testArr, arrLen) << endl;
    return 0;
}
