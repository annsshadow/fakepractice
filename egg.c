# include <stdio.h>
# include <limits.h>
int max(int a, int b) { return (a > b)? a: b; }
int eggDrop(int n, int k)
{
    /* eggFloor[i][j] 表示对于 i个鸡蛋 j 层楼，需要的最少测试次数 */
    int eggFloor[n+1][k+1];
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
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
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
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}