//
// Created by Administrator on 2016/11/14.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("任取一个十进制整数,将其倒过来后与原来的整数想加,得到一个新的整数后重复以上步骤,则最终可以得到一个回文数.\n");
	const long MAX = 2147483647;
	long n, m;
	int count = 0;
	long re(long a);
	int nonre(long s);
	printf("Please input a number optionaly:");
	scanf("%ld", &n);
	printf("The generation process of palindrome: \n");
	while(!nonre((m = re(n)) + n))
	{
		if(m + m >= MAX)
		{
			printf("input error ,break.\n");
			break;
		}
		else
		{
			printf("[%d]:%ld+%ld=%ld\n", ++count, n, m, m + n);
			n += m;
		}
	}
	printf("[%d]:%ld+%ld=%ld", ++count, n, m, m + n);
	printf("\n");
	printf("Here we reached the aim at last!\n");
	system("pause");
	return 0;
}

long re(long a)
{
	long t;
	for(t = 0; a > 0; a /= 10)
	{
		t = t * 10 + a % 10;
	}
	return t;
}

int nonre(long s)
{
	if(re(s) == s)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
