/*********************
    Author:AnnsShadow
    Time = 2015-12-03
*********************/

#include <stdio.h>
#include <stdlib.h>

//每个节点的定义
typedef struct chainNode
{
    struct chainNode *next;
    struct chainNode *previous;
    struct chainNode *child;
    int value;
} chainNode;

/**
为什么tail要用指向指针的指针，因为要修改它啊！
不然在函数里面改了影响不了原来的哦！
**/

//在链表末尾追加链接
void appendChain(chainNode *child, chainNode **tail);
//展开多层链表，使之成为一层
void expandChain(chainNode *head, chainNode **tail);
//将子链表从一层链表中分离
void seperateChild(chainNode *childHead);
//将一层链表还原成多层链表
void unexpandChain(chainNode *head, chainNode **tail);

int main()
{
    chainNode *head, *tail;
    //构造对应的测试多层链表
    /**
        Some codes;
    **/
    expandChain(head, &tail);
    unexpandChain(head, &tail);
    return 0;
}

void appendChain(chainNode *child, chainNode **tail)
{
    //将当前指针赋值为传入的子链表
    chainNode *currentNode = child;
    //原尾指针的下一个赋值为传入的子链表
    (*tail)->next = child;
    //子链表的上一个赋值为原尾指针
    child->previous = *tail;
    //遍历当前子链表直到最后
    for(; currentNode->child; currentNode = currentNode->next);
    //赋值产生新的尾指针
    *tail = currentNode;
}

void expandChain(chainNode *head, chainNode **tail)
{
    //将当前指针指向链表头指针
    chainNode *currentNode = head;
    //当前指针不为NULL
    while(currentNode)
    {
        //如果当前指针有子链表
        if(currentNode->child)
        {
            //将其追加到链表的尾部
            appendChain(currentNode->child, tail);
        }
        //指向下一个指针
        currentNode = currentNode->next;
    }
}

void seperateChild(chainNode *childHead)
{
    //将当前指针赋值为子链表的头指针
    chainNode *currentNode = childHead;
    //当前指针不为空
    while(currentNode)
    {
        //如果当前指针有子链表
        if(currentNode->child)
        {
            //将之前追加到指针‘下一个’的值取消
            //也就是切断链表
            currentNode->child->previous->next = NULL;
            //子链表从主链表分离
            currentNode->child->previous = NULL;
            //如果当前指针有子链表则继续分离
            seperateChild(currentNode->child);
        }
        //指向下一个指针
        currentNode = currentNode->next;
    }
}

void unexpandChain(chainNode *head, chainNode **tail)
{
    //将当前指针赋值为主链表头指针
    chainNode *currentNode = head;
    //开始分离
    seperateChild(head);
    //遍历主链表到末尾
    for(; currentNode->next; currentNode = currentNode->next);
    //重新赋值尾指针
    *tail = currentNode;
}
