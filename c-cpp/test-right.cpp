#include <stdio.h>
#include <stdlib.h>

int main()
{
    short getbits1(unsigned value, int n);
    short getbits2(unsigned short value, int n);
    short a, n, m;
    a = ~0;
    if((a >> 5) != a)
    {
        printf("Logical move!\n");
        m = 0;
    }
    else
    {
        printf("Arithmetic move!\n");
        m = 1;
    }
    printf("Please input a octal number:\n");
    scanf("%o", &a);
    printf("How many digit move towards the right?\n");
    scanf("%d", &n);
    if(0 == m)
        printf("Arithmetic right move,results:%o", getbits1(a, n));
    else
        printf("Logical right move,results:%o", getbits2(a, n));
    system("pause");
    return 0;
}

short getbits1(unsigned value, int n)
{
    unsigned short z;
    z = ~0;
    z = z >> n;
    z = ~z;
    z = z | (value >> n);
    return z;
}

short getbits2(unsigned short value, int n)
{
    unsigned z;
    z = (~(1 >> n)) & (value >> n);
    return z;
}
