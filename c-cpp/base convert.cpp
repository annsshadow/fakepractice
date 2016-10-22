#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100 //定义字符串最大长度
#define SPACE ' ' //定义空格符

void transform(int nsystem, char str[])  //将n进制转换为十进制
{
    int i, num, length;
    char *p, temp[MAX_STR_LEN];
    p = temp;
    while((*p = *str) != '\0')
    {
        while((*p = *str++) == SPACE); //跳过前导空格,注意是分号结尾
        *++p = *str++;
        while((*p != SPACE) && (*p != '\0'))   //遇到空格或'\0'时,*p才停止读入
        {
            *++p = *str++;
        } //while
        *p = '\0';
        str--; //如果上面*p是遇到'\0'而停止读入时，应让str退一步以指回向'\0'，如果是遇到空格而停止读入的，则str自减一也只是退一步重新指向了空格符，对后续操作不影响
        num = 0;
        length = strlen(temp);
        for(i = 0; i < length; i++)   //由于加了输入防错处理，所以temp[i]肯定是合法字符
        {
            if(temp[i] <= '9') temp[i] -= '0';
            else if(temp[i] <= 'F') temp[i] = temp[i] - 'A' + 10;
            else if(temp[i] <= 'f') temp[i] = temp[i] - 'a' + 10;
            num += pow(nsystem, length - 1 - i) * temp[i];
        } //for
        printf("%d ", num);
        p = temp;
    } //while
} //transform

int main()
{
    int i, nsystem; //n进制
    char str[MAX_STR_LEN];
    printf("此为将二,八,十六进制转换为十进制程序!\n");
    printf("请选择要转换的进制(输入2或8或16):  ");
    scanf("%d", &nsystem);
    getchar(); //吃掉输入产生的回车符
    while((nsystem != 2) && (nsystem != 8) && (nsystem != 16))
    {
        printf("您输入的进制错误，请重新输入: ");
        scanf("%d", &nsystem);
        getchar();
    } //while
    printf("请输入要转换的数(如有多个,请用空格分开,不超过%d个字符):\n", MAX_STR_LEN - 1);
    i = 0;
    while((i < MAX_STR_LEN - 2) && ((str[i] = getchar()) != '\n'))
    {
        if((nsystem == 2) && ((str[i] >= '0') && (str[i] <= '1') || (str[i] == SPACE)))
        {
            i++;
            continue;
        } //if
        if((nsystem == 8) && ((str[i] >= '0') && (str[i] <= '8') || (str[i] == SPACE)))
        {
            i++;
            continue;
        } //if
        if((nsystem == 16) && ((str[i] >= '0') && (str[i] <= '9') || (str[i] >= 'a') && (str[i] <= 'z') || (str[i] >= 'A') && (str[i] <= 'Z') || (str[i] == SPACE)))   //这些为十六进制合法字符
        {
            i++;
            continue;
        } //if
        printf("您输入的%d进制数不合法,请重新输入:\n", nsystem);
        setbuf(stdin, NULL); //将输入缓冲区设置为空
        i = 0;
    } //while
    str[i] = '\0';
    printf("转换后为:\n");
    transform(nsystem, str);
    printf("\n");
    return 0;
} //main
