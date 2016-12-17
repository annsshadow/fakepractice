//
// Created by Administrator on 2016/11/5.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("任何一个整数的立方数都可以写成一串连续奇数的和.\n");
	int a, b, c, d;
	printf("Please enter a number:\n");
	scanf("%d", &a);
	b = a * a * a;
	printf("%d*%d*%d=%d =", a, a, a, b);
	for(d = 0, c = 0; c < a; c++)
	{
		d += a * a - a + 1 + c * 2;
		printf(c ? "+%d" : "%d", a * a - a + 1 + c * 2);
	}
	printf("\n");
	if(d == b)
	{
		printf("Y\n");
	}
	else
	{
		printf("N\n");
	}
	system("pause");
	return 0;
}
