//
// Created by Administrator on 2016/10/29.
//
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void movedisc(unsigned n, char fromneedle, char toneedle, char usingneedle);

int main()
{
	unsigned n;
	void movedisc(unsigned n, char fromneedle, char toneedle, char usingneedle);
	printf("Please input the number of discs:\n");
	scanf("%d", &n);
	printf("\tneedle:\ta\tb\tc\n");
	movedisc(n, 'a', 'c', 'b');
	printf("\tTotal:%d\n", count);
	system("pause");
	return 0;
}

void movedisc(unsigned n, char fromneedle, char toneedle, char usingneedle)
{
	if(n > 0)
	{
		movedisc(n - 1, fromneedle, usingneedle, toneedle);
		++count;
		switch(fromneedle)
		{
			case 'a':
				switch(toneedle)
				{
					case 'b':
						printf("\t[%d]:\t%2d------->%2d\n", count, n, n);
						break;
					case 'c':
						printf("\t[%d]:\t%2d------->%2d\n", count, n, n);
						break;
				}
				break;
			case 'b':
				switch(toneedle)
				{
					case 'a':
						printf("\t[%d]:\t%2d<--------------%2d\n", count, n, n);
						break;
					case 'c':
						printf("\t[%d]:\t%2d------->%2d\n", count, n, n);
						break;
				}
				break;
			case 'c':
				switch(toneedle)
				{
					case 'a':
						printf("\t[%d]:\t%2d<--------------%2d\n", count, n, n);
						break;
					case 'b':
						printf("\t[%d]:\t%2d<-------%2d\n", count, n, n);
						break;
				}
				break;
		}
		movedisc(n - 1, usingneedle, toneedle, fromneedle);
	}
}

