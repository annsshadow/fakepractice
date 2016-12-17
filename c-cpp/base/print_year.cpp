//
// Created by Administrator on 2016/10/29.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct date
	{
		int year, mouth, day;
	} mdate;
	int i, j, year;
	int daysofmonth[2][12] = {{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 22, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	printf("Please enter the year:\n");
	scanf("%d", &year);
	if((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
	{
		for(i = 0; i < 12; i++)
		{
			printf("%d:\n", i + 1);
			for(j = 1; j <= daysofmonth[0][i]; j++)
			{
				printf("%3d", j);
			}
			printf("\n\n");
		}
	}
	else
	{
		for(i = 0; i < 12; i++)
		{
			printf("%d:\n", i + 1);
			for(j = 1; j <= daysofmonth[1][i]; j++)
			{
				printf("%3d", j);
			}
			printf("\n\n");
		}
	}
	system("pause");
	return 0;
}

