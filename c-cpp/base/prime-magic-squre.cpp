//
// Created by Administrator on 2016/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;//可逆素数的数目
int number[210][5];//存放可逆素数及素数分解后的各位数

int select[110];//可以放在矩阵第一行和最后一行的素数的下标
int selecount;//可以放在矩阵第一行和最后一行的可逆素数的数目

int array[4][5];//4x4的矩阵,每行0号元素存可逆素数对应的数组下标

int larray[2][200];//存放素数前二,三位数值的临时数组
int lcount[2];//存放素数前二,三位的临时数组所对应的数量计数器

int main()
{
	printf("求四阶的素数幻方\n即在一个4x4的矩阵中,买一个格子填入一个数字,使每一行,每一列和两条对角线上的4个数字组成的四位数是可逆素数.\n");

	int i, k, flag, cc = 0, i1, i4;

	int ok(int number);
	int num(int number);
	int find0(int num);
	int find1(int i);
	int find2(void);
	void process(int i);
	void p_array(void);
	void copy_num(int i);
	int comp_num(int n);

	printf("There are following squares with invertable primes as follows:\n");
	for(i = 1001; i < 9999; i += 2)
	{
		k = i / 1000;
		if(k % 2 != 0 && k != 5 && num(i))//可逆素数第一位非偶非5
		{
			number[count][0] = i;
			process(count++);
			if(number[count - 1][2] % 2 != 0 &&
			   number[count - 1][3] % 2 != 0 &&
			   number[count - 1][2] != 5 &&
			   number[count - 1][3] != 5)
			{
				select[selecount++] = count - 1; //数的下标,计数器加1
			}
		}
	}
	larray[0][lcount[0]++] = number[0][0] / 100;//第一行存前两位
	larray[1][lcount[1]++] = number[0][0] / 10;//第二行存前三位
	for(i = 1; i < count; i++) //将数组不重复的前二,三位存入临时数组
	{
		if(larray[0][lcount[0] - 1] != number[i][0] / 100)
		{
			larray[0][lcount[0]++] = number[i][0] / 100;
		}
		if(larray[1][lcount[1] - 1] != number[i][0] / 10)
		{
			larray[1][lcount[1]++] = number[i][0] / 10;
		}
	}
	for(i1 = 0; i1 < selecount; i1++) //第一行
	{
		array[0][0] = select[i1];//去对应素数下标
		copy_num(0);//复制分解的数字
		for(array[1][0] = 0; array[1][0] < count; array[1][0]++) //第二行
		{
			copy_num(1);
			if(!comp_num(2))//每列的前两位的组成与素数矛盾,则下一个
			{
				continue;
			}
			for(array[2][0] = 0; array[2][0] < count; array[2][0]++)
			{
				copy_num(2);
				if(!comp_num(3))//每列的前三位~~
				{
					continue;
				}
				for(i4 = 0; i4 < selecount; i4++)
				{
					array[3][0] = select[i4];
					copy_num(3);
					for(flag = 1, i = 1; flag && i <= 4; i++) //判断每列是不是可逆素数
					{
						if(!find1(i))
						{
							flag = 0;
						}
					}
					if(flag && find2())
					{
						printf("No.%d\n", ++cc);
						p_array();
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

int ok(int number)//判断是否为素数
{
	int i, j;
	if(0 == number % 2)
	{
		return 0;
	}
	j = (int)sqrt((double)number) + 1;
	for(i = 3; i <= j; i += 2)
	{
		if(0 == number % i)
		{
			return 0;
		}
	}
	return 1;
}

int num(int number)//判断是否为可逆素数
{
	int j;
	if(!ok(number))
	{
		return 0;
	}
	for(j = 0; number > 0; number /= 10)
	{
		j = j * 10 + number % 10;
	}
	if(!ok(j))
	{
		return 0;
	}
	return 1;
}

void process(int i)//将第i个整数分解为数字并存入数组
{
	int j, num;
	num = number[i][0];
	for(j = 4; j >= 1; j--, num /= 10)
	{
		number[i][j] = num % 10;
	}
}

void copy_num(int i)//将array[i][0]指向的素数的各位数字复制到array[i]中.
{
	int j;
	for(j = 1; j <= 4; j++)
	{
		array[i][j] = number[array[i][0]][j];
	}
}

int comp_num(int n)//判断array中的每一列的前n位是否与可你素数允许的前n位矛盾
{
	static int ii;//保存前一次查找到的元素下标,前一次查找前两位的的下表
	static int jj;//前一次查找前三位的下标
	int i, num, k, *p; //指向对应的要使用的"前一次下标"ii或jj
	int *pcount;//指向对应的要使用的临时数组数量的计数器
	switch (n)
	{
		case 2:
			pcount = &lcount[0];
			p = &ii;
			break;
		case 3:
			pcount = &lcount[1];
			p = &jj;
			break;
		default :
			return 0;
	}
	for(i = 1; i <= 4; i++) //4列分别处理
	{
		for(num = 0, k = 0; k < n; k++)
		{
			num = num * 10 + array[k][i];
		}
		if(num <= larray[n - 2][*p])//与前一次最后查找的元素进行比较
		{
			for(; *p >= 0 && num < larray[n - 2][*p]; (*p)--);
		}
		else
		{
			for(; *p < *pcount && num > larray[n - 2][*p] ; (*p)++ );
		}
		if(*p < 0 || *p >= *pcount)
		{
			*p = 0;
			return 0;
		}
		if(num != larray[n - 2][*p])
		{
			return 0;//前n位不是可逆素数允许的值则为0
		}
	}
	return 1;
}

int find0(int num)//判断是否为满足要求的可逆素数
{
	static int j;
	if(num <= number[j][0])
	{
		for(; j >= 0 && num < number[j][0]; j--)
		{
		}
	}
	else
	{
		for(; j < count && num > number[j][0]; j++)
		{
		}
	}
	if(j < 0 || j >= count)
	{
		j = 0;
		return 0;
	}
	if(num == number[j][0])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int find1(int i)//判断列方向是否为可逆素数
{
	int num, j;
	for(num = 0, j = 0; j < 4; j++)
	{
		num = num * 10 + array[j][i];
	}
	return (find0(num));
}

int find2(void)//判断对角线方向是否是可逆素数
{
	int num1, num2, i, j;
	for(num1 = 0, j = 0; j < 4; j++)
	{
		num1 = num1 * 10 + array[j][j + 1];
	}
	for(num2 = 0, j = 0, i = 4; j < 4; j++, i--)
	{
		num2 = num2 * 10 + array[j][i];
	}
	if(find0(num1))
	{
		return (find0(num2));
	}
	else
	{
		return 0;
	}
}

void p_array(void)//输出矩阵
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		for(j = 1; j <= 4; j++)
		{
			printf("%6d", array[i][j]);
		}
		printf("\n");
	}
}

/*
可优化方案:
1.设定前三行后不必穷举最后一行
可在可逆素数中找出前三位与设定好的三维数字相同的素数
找出全部各列可能的取值,求出交集,有则填入到矩阵中;
2.可先穷举一,二和四列的数据,再用1.中算法确定第三行;
3.可以只输出17个基本解,每个都可以通过旋转和反射获得同构体;
*/
