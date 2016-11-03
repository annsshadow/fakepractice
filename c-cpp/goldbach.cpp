//
// Created by Administrator on 2016/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	printf("验证2000以内的正偶数都能够分解为两个素数之和.\n");
	const int size = 2000;
	int prime(int i);
	int i, n;
	for(i = 4; i <= size; i += 2)
	{
		for(n = 2; n < i; n++)
		{
			if(prime(n))
			{
				if(prime(i - n))
				{
					printf("%d = %d + %d\n", i, n, i - n);
					break;
				}
			}
			if(n == i)
			{
				printf("error %d\n", i);
			}
		}
	}
	return 0;
}

int prime (int i)
{
	int j;
	if(i <= 1)
	{
		return 0;
	}
	if( 2 == i)
	{
		return 1;
	}
	if(!(i % 2))
	{
		return 0;
	}
	for(j = 3; j <= (int)(sqrt((double)i + 1)); j++)
	{
		if(!(i % j))
		{
			return 0;
		}
	}
	return 1;
}
