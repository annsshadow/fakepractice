//
// Created by Administrator on 2016/11/15.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("使用数组精确计算M/N(0<=M<N<=100)的值\n如果其时无限循环小数,则计算并输出它的第一循环节,同时要求输出循环节的起始位置(小数位的序号)\n");
	int m, n, i, j;
	int remainder[101] = {0}, quotient[101];
	printf("Please input a fraction(m/n)(0<=M<N<=100):\n");
	scanf("%d/%d", &m, &n);
	printf("%d/%d it's accuracy value is :0.", m, n);
	for(i = 1; i <= 100; i++) //i 商的位数
	{
		remainder[m] = i;//k为除的余数 remainder[i]是该余数对应的商的位数
		m *= 10;
		quotient[i] = m / n;//商
		m = m % n;
		if(0 == m)//余数为0,表示有限小数
		{
			for(j = 1; j <= i; j++)
			{
				printf("%d", quotient[j]);
			}
			break;
		}
		if(remainder[m] != 0)//余数对应的位数已经出现过
		{
			for(j = 1; j <= i; j++)
			{
				printf("%d", quotient[j]); //输出循环小数
			}
			printf("\n\ttand it is a infinite cyclic fraction from %d\n", remainder[m]);
			printf("\tdigit to %d digit after decimal point.\n", i); //输出循环节的位置
			break;
		}
	}
	system("pause");
	return 0;
}
