//
// Created by Administrator on 2016/11/8.
//

#include <stdio.h>
//乘积的最后三位的值只与乘数与被乘数的后三位有关,与乘数和被乘数的高位无关.
int main()
{
	int i, x, y, last = 1;
	printf("This program is to find the last three digits of the Y power of X.\n");
	printf("Input X and Y.\nThe X is the base number.\nThe Y is the power\n");
	scanf("%d%d", &x, &y);
	for(i = 1; i <= y; i++)
	{
		last = last * x % 1000;
	}
	printf("The last three digits of the %d power of %d is %d.\n ", y, x, last);
	return 0;
}
