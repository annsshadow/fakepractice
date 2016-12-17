//
// Created by Administrator on 2016/11/12.
//

#include <stdio.h>
#include <math.h>
//用数组会更加简单；
int main()
{
	double y;
	int x, m;
	for(y = 1; y >= -1; y -= 0.1) //步长为0.1；
	{
		m = acos(y) * 10;//放大倍数
		for(x = 1; x < m; x++)
		{
			printf(" ");
		}
		printf("*");//左侧*

		for(; x < 66 - m; x++) //总的列数
		{
			printf(" ");
		}
		printf("*\n");//对应右侧*
	}
	return 0;
}
