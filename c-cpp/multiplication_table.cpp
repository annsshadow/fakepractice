//
// Created by Administrator on 2016/10/29.
//

/*
#include <stdio.h>
int main()
{
	int i,j,k;
	printf("\t");
	for (i = 1;i <= 9;i++)
	{
		printf("%d\t",i);          //输出上标题
	}
	printf("\n");
	for (i=1;i<=9;i++)
	{
		printf("%d\t",i);       //输出列行数
		for (k=2;k<=i;k++)
		{
			printf("\t");           //控制输出时的位置
		}
		for (j=i;j<=9;j++)
		{
			printf("%d\t",i*j);         //输出值
		}
		printf("\n");
	}
	return 0;
}
*/

#include <stdio.h>
int main()
{
	int i, j, k;
	printf("\t");
	for (i = 1; i <= 9; i++)
	{
		printf("%d\t", i);
	}

	printf("\n");
	printf("\t");

	for (i = 1; i <= 9; i++)
	{
		printf("-\t");
	}

	for (i = 1; i <= 9; i++)
	{
		printf("%d\t", i);
		for(k = 2; k <= i; k++)
		{
			printf("\t");
		}
		for(j = i; j <= 9; j++)
		{
			printf("%d\t", i * j);
		}
		printf("\n");
	}

	return 0;
}
