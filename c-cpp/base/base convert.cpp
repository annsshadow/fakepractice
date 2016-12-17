#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100 //�����ַ�����󳤶�
#define SPACE ' ' //����ո��

void transform(int nsystem, char str[])  //��n����ת��Ϊʮ����
{
    int i, num, length;
    char *p, temp[MAX_STR_LEN];
    p = temp;
    while((*p = *str) != '\0')
    {
        while((*p = *str++) == SPACE); //����ǰ���ո�,ע���ǷֺŽ�β
        *++p = *str++;
        while((*p != SPACE) && (*p != '\0'))   //�����ո��'\0'ʱ,*p��ֹͣ����
        {
            *++p = *str++;
        } //while
        *p = '\0';
        str--; //�������*p������'\0'��ֹͣ����ʱ��Ӧ��str��һ����ָ����'\0'������������ո��ֹͣ����ģ���str�Լ�һҲֻ����һ������ָ���˿ո�����Ժ���������Ӱ��
        num = 0;
        length = strlen(temp);
        for(i = 0; i < length; i++)   //���ڼ����������������temp[i]�϶��ǺϷ��ַ�
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
    int i, nsystem; //n����
    char str[MAX_STR_LEN];
    printf("��Ϊ����,��,ʮ������ת��Ϊʮ���Ƴ���!\n");
    printf("��ѡ��Ҫת���Ľ���(����2��8��16):  ");
    scanf("%d", &nsystem);
    getchar(); //�Ե���������Ļس���
    while((nsystem != 2) && (nsystem != 8) && (nsystem != 16))
    {
        printf("������Ľ��ƴ�������������: ");
        scanf("%d", &nsystem);
        getchar();
    } //while
    printf("������Ҫת������(���ж��,���ÿո�ֿ�,������%d���ַ�):\n", MAX_STR_LEN - 1);
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
        if((nsystem == 16) && ((str[i] >= '0') && (str[i] <= '9') || (str[i] >= 'a') && (str[i] <= 'z') || (str[i] >= 'A') && (str[i] <= 'Z') || (str[i] == SPACE)))   //��ЩΪʮ�����ƺϷ��ַ�
        {
            i++;
            continue;
        } //if
        printf("�������%d���������Ϸ�,����������:\n", nsystem);
        setbuf(stdin, NULL); //�����뻺��������Ϊ��
        i = 0;
    } //while
    str[i] = '\0';
    printf("ת����Ϊ:\n");
    transform(nsystem, str);
    printf("\n");
    return 0;
} //main
