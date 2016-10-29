#include<stdio.h>
int main()
{
	int an = -1, bn = -1, max, flag = 0;
	char a[50] = {'0'}, b[50] = {'0'}, sum[50] = {'0'}, c;
	printf("\n\tEnter the Number:\n");
	c = getchar();

	while(c >= '0' && c <= '9' && c != '\n')
	{
		an++;
		a[an] = c;
		c = getchar();
	}

	printf("\n%s+", a);
	c = getchar();

	while(c >= '0' && c <= '9' && c != '=')
	{
		bn++;
		b[bn] = c;
		c = getchar();
	}

	printf("%s=", b);

	if(an > bn)
		max = an;
	else
		max = bn;

	while(max >= 0)
	{
		if(an >= 0 && bn >= 0)
		{
			if(a[an] - '0' + b[bn] - '0' > 9)
			{
				sum[max] = a[an] - '0' + b[bn] - 10 + flag;
				flag = 1;
			}
			else
			{
				sum[max] = a[an] - '0' + b[bn] + flag;
				flag = 0;
			}

			an--;
			bn--;
		}
		else
		{
			if(an < 0 && bn >= 0)
			{
				if(b[bn] + flag - '0' > 9)
				{
					sum[max] = '0';
					flag = 1;
					bn--;
				}
				else
				{
					sum[max] = b[bn] + flag;
					flag = 0;
					bn--;
				}
			}
			else
				if(bn < 0 && an >= 0)
				{
					if(a[an] + flag - '0' > 9)
					{
						sum[max] = '0';
						flag = 1;
						an--;
					}
					else
					{
						sum[max] = a[an] + flag;
						flag = 0;
						an--;
					}
				}
		}

		max--;
	}

	if(flag)
		printf("1%s\n", sum);
	else
		printf("%s\n", sum);
	return 0;
}
