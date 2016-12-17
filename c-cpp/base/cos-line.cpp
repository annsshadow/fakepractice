//
// Created by Administrator on 2016/11/13.
//

#include <stdio.h>
#include <math.h>

int main()
{
	double y;
	int x, m, n, yy; //整形的结果是近似的
	printf("This is to print the picture of the y=cos(x) and the y = 45 * (x - 1) + 31.\n");

	for(yy = 0; yy <= 20; yy++) //yy是打印的行数,y是行方向坐标
	{
		y = 0.1 * yy;
		m = acos(1 - y) * 10;//1-y的范围是(1,-1)
		n = 45 * (y - 1) + 31;

		for(x = 0; x <= 62; x++) //列数=62
		{
			if (x == m && x == n)
			{
				printf("+");//打印相交
			}
			else if(x == n)
			{
				printf("+");//不相交的直线
			}
			else if(x == m || x == 62 - m)
			{
				printf("*");;//不相交的余弦
			}
			else
			{
				printf(" ");//其他情况
			}
		}
		printf("\n");//注意:每一个点后换行!
	}
	return 0;
}
