/*********************
    Author:AnnsShadow
    Time = 2015-12-03
*********************/

#include <stdio.h>
#include <stdlib.h>

//ÿ���ڵ�Ķ���
typedef struct chainNode
{
    struct chainNode *next;
    struct chainNode *previous;
    struct chainNode *child;
    int value;
} chainNode;

/**
ΪʲôtailҪ��ָ��ָ���ָ�룬��ΪҪ�޸�������
��Ȼ�ں����������Ӱ�첻��ԭ����Ŷ��
**/

//������ĩβ׷������
void appendChain(chainNode *child, chainNode **tail);
//չ���������ʹ֮��Ϊһ��
void expandChain(chainNode *head, chainNode **tail);
//���������һ�������з���
void seperateChild(chainNode *childHead);
//��һ������ԭ�ɶ������
void unexpandChain(chainNode *head, chainNode **tail);

int main()
{
    chainNode *head, *tail;
    //�����Ӧ�Ĳ��Զ������
    /**
        Some codes;
    **/
    expandChain(head, &tail);
    unexpandChain(head, &tail);
    return 0;
}

void appendChain(chainNode *child, chainNode **tail)
{
    //����ǰָ�븳ֵΪ�����������
    chainNode *currentNode = child;
    //ԭβָ�����һ����ֵΪ�����������
    (*tail)->next = child;
    //���������һ����ֵΪԭβָ��
    child->previous = *tail;
    //������ǰ������ֱ�����
    for(; currentNode->child; currentNode = currentNode->next);
    //��ֵ�����µ�βָ��
    *tail = currentNode;
}

void expandChain(chainNode *head, chainNode **tail)
{
    //����ǰָ��ָ������ͷָ��
    chainNode *currentNode = head;
    //��ǰָ�벻ΪNULL
    while(currentNode)
    {
        //�����ǰָ����������
        if(currentNode->child)
        {
            //����׷�ӵ������β��
            appendChain(currentNode->child, tail);
        }
        //ָ����һ��ָ��
        currentNode = currentNode->next;
    }
}

void seperateChild(chainNode *childHead)
{
    //����ǰָ�븳ֵΪ�������ͷָ��
    chainNode *currentNode = childHead;
    //��ǰָ�벻Ϊ��
    while(currentNode)
    {
        //�����ǰָ����������
        if(currentNode->child)
        {
            //��֮ǰ׷�ӵ�ָ�롮��һ������ֵȡ��
            //Ҳ�����ж�����
            currentNode->child->previous->next = NULL;
            //����������������
            currentNode->child->previous = NULL;
            //�����ǰָ�������������������
            seperateChild(currentNode->child);
        }
        //ָ����һ��ָ��
        currentNode = currentNode->next;
    }
}

void unexpandChain(chainNode *head, chainNode **tail)
{
    //����ǰָ�븳ֵΪ������ͷָ��
    chainNode *currentNode = head;
    //��ʼ����
    seperateChild(head);
    //����������ĩβ
    for(; currentNode->next; currentNode = currentNode->next);
    //���¸�ֵβָ��
    *tail = currentNode;
}
