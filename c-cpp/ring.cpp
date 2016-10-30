//
// Created by Administrator on 2016/10/30.
//

#include <stdio.h>
#include <math.h>
int main()
{
	double y;
	int x,m;
	printf("This is to print a circle.\n");
	for(y = 10;y >= -10;y--)//假设半径为10
	{
		m = 2.15 * sqrt(100 - pow(y,2));
		//2.15是屏幕纵横比调节系数,否则为椭圆
		//计算y对应的列坐标m
		for(x = 1;x < 30 - m;x++)//x要从1开始
		{//30的用意????????
			printf(" ");
		}
		printf("*");//左侧

		for(;x < 30 + m;x++)//控制空心部分
		{
			printf(" ");
		}
		printf("*\n");//右侧
	}
	return 0;
}
