//
// Created by Administrator on 2016/11/6.
//

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, m;
	int ysf(int n, int m);
	printf("Please input the total number:\n");
	scanf("%d", &n);
	printf("Please input the limit:\n");
	scanf("%d", &m);
	printf("\n");
	ysf(n, m);
	system("pause");
	return 0;
}

int ysf(int n, int m)
{
	int a[100], i, j, k, num;
	for(i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	for(j = 0, k = 0, i = 1; i <= n; i++)
	{
		if(a[i] = 1)
		{
			j = j + a[i];
			if(j == m)
			{
				printf("%d\n", i);
				j = 0;
				a[i] = 0;
				k++;
			}
			if(k == n)
			{
				num = i;
				break;
			}

		}
		if(i == n)
		{
			i = 0;
		}
	}
}

/*
#include<stdio.h>
#define size 100                    //输入人数的上限
void main()
{
 int person[size];
 int i, j;                        //循环修正变量
 int arrayLen;                    //数组长度
 int start, overNum;              //开始位置各跨过位置
 int deleNum;                     //出列人所在数组中的下标
 int name, total;                 //输入时,人的信息以及人的总数
 printf( "请输入圆桌上人的总数: " );
 scanf( "%d", &arrayLen ); printf( "\n" );
 if( ( arrayLen > size ) || ( arrayLen < 0 ) )
 {
  printf( "超出范围,请重新输入: " );
  scanf( "%d", &arrayLen ); printf( "\n" );
 };
 printf( "请输入各个人的信息(整数): \n" );
 for( i = 0; i < arrayLen; i++ )
 {
  scanf( "%d", &name );
  person[i] = name;
 }
 printf( "你输入的数据的顺序为: \n" );
 for( i = 0; i < arrayLen - 1; i++ )
  printf( " %d ==>", person[i] );
 printf( "%d \n", person[arrayLen - 1] );
 printf( "你打算从第几个人开始? 请输入开始号: " );
 scanf( "%d", &start );
 printf( "\n" );
 start = start - 1;
 printf( "请输入相邻两出列人之间的间隔: " );
 scanf( "%d", &overNum );
 printf( "\n" );

 total = arrayLen;
 printf( "程序运行后,出列人的顺序为:\n\n" );
 for( i = 0; i < total; i++ )                    //要打印total个人的情况,故做total次
 {
  if ( arrayLen == 1 )
   printf( "%d", person[0] );                    //如果是数组只剩一个元素,直接出列
  else
  {
   deleNum = ( start + overNum - 1 ) % arrayLen; //此取模保证循环
   printf( "%d ==> ", person[deleNum] );
   for ( j = deleNum; j < arrayLen; j++ )        //将出列元素后面的各元素前移
    person[j] = person[j+1];
   start = deleNum;
   arrayLen = arrayLen - 1;                      //移动完毕后,数组长度减1
  }
 }
 printf( "\n\n" );
}

从一本数据结构书上看到的用向量实现此问题：
void Josephus (Vector <int> &P, int n, int s, int m)
{
//将人员编号存入向量P；
int k = 1;
for(int i = 0; i<n, i++)
{P.Insert(k,i); k++;}
int s1 = s;
for(int j = n; j>=1; j--)
{
s1=(s1+m-1)%j;
if(s1== 0)   s1 = j;
int w = P.Getnode(s1 - 1);
P.Remvoe(s1 - 1);
P.Insert(w,n-1);
}
}*/
