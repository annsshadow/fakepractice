//
// Created by Administrator on 2016/11/14.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, s, t;
	const int size = 1000;
	int a(int n);
	printf("Following are palinndrome primes not greater than %d\n", size);
	for(i = 0; i <= 9; i++)
	{
		for(j = 0; j <= 9; j++)
		{
			for(k = 0; k <= 9; k++)
			{
				s = i * 100 + j * 10 + k;
				t = k * 100 + j * 10 + i;
				if(0 == i && 0 == j)//处理整数前两位为0的情况
				{
					t /= 100;
				}
				else if(i == 0)//处理整数第一位为0的情况
				{
					t /= 10;
				}
				if(s > 10 && s == t && a(s))
				{
					printf("%d\t", s);
				}
			}
		}
	}
	system("pause");
	return 0;
}

int a(int n)
{
	int i;
	for(i = 2; i <= (n - 1) / 2; i++)
	{
		if(0 == n % i)
		{
			return 0;
		}
	}
	return 1;
}

