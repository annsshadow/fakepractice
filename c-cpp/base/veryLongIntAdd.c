
#include <stdio.h>
#include <stdlib.h>

#define HUNTHOU 10000

typedef struct node
{
    int data;
    struct node *next;
} NODE;     //��������ṹ

NODE *insert_after(NODE *u, int num);   //��u�������һ���µ�NODE����ֵΪnum
NODE *addint(NODE *p, NODE *q); //��ɼӷ���������ָ��*p+*q�����ָ��
void printint(NODE *s);         //��ӡ����������
NODE *inputint(void);       //���볬��������

int main()
{
    NODE *s1, *s2, *s;
    printf("Enter S1= ");
    s1 = inputint();    //���뱻����
    printf("Enter S2= ");
    s2 = inputint();    //�������
    printf(" S1=");
    printint(s1);       //��ʾ������
    putchar('\n');
    printf(" S2=");
    printint(s2);       //��ʾ����
    putchar('\n');
    s = addint(s1, s2);     //���
    printf("S1+S2=");
    printint(s);        //������
    putchar('\n');
    return 0;
}

NODE *insert_after(NODE *u, int num)
{
    NODE *v;
    v = (NODE *) malloc(sizeof(NODE));   //����һ��NODE
    v->data = num;   //��ֵ
    u->next = v;         //��u�������һ��NODE
    return v;
}

NODE *addint(NODE *p, NODE *q)      //��ɼӷ���������ָ��*p+*q�����ָ��
{
    NODE *pp, *qq, *r, *s, *t;
    int total, number, carry;
    pp = p->next;
    qq = q->next;
    s = (NODE *) malloc(sizeof(NODE)); //������ź͵������ͷ
    s->data = -1;
    t = s;
    carry = 0;      //carry:��λ

    while (pp->data != -1 && qq->data != -1) //�����Ǳ�ͷ
    {
        total = pp->data + qq->data + carry;  //��Ӧλ��ǰ�εĽ�λ���
        number = total % HUNTHOU;       //����������в��ֵ���ֵ
        carry = total / HUNTHOU;        //�����λ
        t = insert_after(t, number);    //�����ֺʹ���sָ�������
        pp = pp->next;       //�ֱ�ȡ����ļ���
        qq = qq->next;
    }

    r = (pp->data != -1) ? pp : qq; //ȡ��δ������ϵ���ָ��

    while (r->data != -1)     //��������нϴ����
    {
        total = r->data + carry; //���λ���
        number = total % HUNTHOU;   //����������в��ֵ���ֵ
        carry = total / HUNTHOU;    //�����λ
        t = insert_after(t, number);    //�����ֺʹ���sָ�������
        r = r->next;     //ȡ�����ֵ
    }

    if (carry) t = insert_after(t, 1); //�������һ�ν�λ

    t->next = s;     //��ɺ͵�����
    return s;       //����ָ��͵Ľṹָ��
}

NODE *inputint(void)        //���볬��������
{
    NODE *s, *ps, *qs;
    struct number
    {
        int num;
        struct number *np;
    } *p, *q;
    int i, k;
    long sum;
    char c;
    p = NULL;   //ָ�����������������Ϊ��������͵ĸ�λ����βΪ���������λ

    while ((c = getchar()) != '\n')  //�������������ַ���������
    {
        if (c >= '0' && c <= '9')      //��Ϊ���������
        {
            q = (struct number *) malloc(sizeof(struct number));     //����ռ�
            q->num = c - '0';    //����һλ����
            q->np = p;   //����ָ��
            p = q;
        }
    }

    s = (NODE *) malloc(sizeof(NODE));
    s->data = -1;    //�������󳬳�����������ͷ
    ps = s;

    while (p != NULL)    //�����յ���ʱ�������е�����ת��Ϊ��Ҫ��ı�׼��ʽ
    {
        sum = 0;
        i = 0;
        k = 1;

        while (i < 4 && p != NULL) //ȡ������λ
        {
            sum = sum + k * (p->num);
            i++;
            p = p->np;
            k = k * 10;
        }

        qs = (NODE *) malloc(sizeof(NODE));      //����ռ�
        qs->data = sum;      //��ֵ����������
        ps->next = qs;
        ps = qs;
    }

    ps->next = s;    //���һ��Ԫ�ص�ָ��ָ����ͷ
    return s;
}

void printint(NODE *s)          //��ӡ����������
{
    if (s->next->data != -1)   //�����Ǳ�ͷ�������
    {
        printint(s->next);       //�ݹ����

        if (s->next->next->data == -1)
        {
            printf("%d", s->next->data);
        }
        else
        {
            int i, k = HUNTHOU;

            for (i = 1; i <= 4; i++, k /= 10)
            {
                putchar('0' + s->next->data % (k) / (k / 10));
            }
        }
    }
}

