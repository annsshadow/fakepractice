//
// Created by Administrator on 2016/11/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int MAX = 10;
	int a[MAX][MAX], n, x, y, tot = 0;
	printf("Please input a nunber:\n");
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	tot = a[x = 0][y = n - 1] = 1;
	while(tot < n * n)
	{
		while(x + 1 < n && !a[x + 1][y])
		{
			a[++x][y] = ++tot;
		}
		while(y - 1 >= 0 && !a[x][y - 1])
		{
			a[x][--y] = ++tot;
		}
		while(x - 1 >= 0 && !a[x - 1][y])
		{
			a[--x][y] = ++tot;
		}
		while(y + 1 < n && !a[x][y + 1])
		{
			a[x][++y] = ++tot;
		}
	}
	for(x = 0; x < n; x++)
	{
		for(y = 0; y < n; y++)
			printf("%3d", a[x][y]);
		printf("\n");
	}
	system("pause");
	return 0;
}
