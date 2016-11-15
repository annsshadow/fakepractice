//
// Created by Administrator on 2016/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//保留数据的节点
typedef struct node
{
	int date;
	struct node*next;
} Node;

//链表的节点管理,包括表头和链表节点的数量
typedef struct nodectrl
{
	Node *head;
	int num;
} NodeCtrl;

int main()
{
	void Display(NodeCtrl * nc);
	void FreeNodeCtrl(NodeCtrl * nc);
	int AddDate(NodeCtrl * nc, int date);
	NodeCtrl *CreateCtrl();
	int i, date;
	NodeCtrl *nc1 = CreateCtrl();
	NodeCtrl *nc2 = CreateCtrl();

	for(i = 0; i < 3; i++)
	{
		scanf("%d", &date);
		AddDate(nc1, date);
	}

	Display(nc1);
	FreeNodeCtrl(nc1);
	system("pause");
	return 0;
}


//申请管理节点的空间,并初始化表头和节点数量值
NodeCtrl *CreateCtrl()
{
	NodeCtrl *nc = (NodeCtrl*)malloc(sizeof(NodeCtrl));

	if(nc == NULL)
	{
		puts("Creat NodeCtrl failed!");
		return NULL;
	}

	//由于刚建立管理节点,链表中没有任何节点
	nc->head = NULL;
	nc->num = 0;
	return nc;
}

//根据管理节点内存位置,加入一个新的数据(数据节点);
int AddDate(NodeCtrl *nc, int date)
{
	Node *p, *q;

	if(nc == NULL)
		return EOF;

	//新申请一个Node节点,用来保留date数据
	q = (Node*)malloc(sizeof(Node));

	if(q == NULL)
		return EOF;

	//保留数据
	q->date = date;
	q->next = NULL;
	//找到链表的头节点,准备插入数据
	p = nc->head;

	//插入数据(头插法)
	if(p != NULL)
		q->next = nc->head;

	nc->head = q;
	//由于增加了一个节点,节点数量需要加1
	nc->num++;
	return 0;
}

//释放管理节点保留的链表,先释放链表,再释放管理节点
void FreeNodeCtrl(NodeCtrl *nc)
{
	//定义两个临时指针,q负责保留上次的节点,p负责向下寻找下一个节点
	Node *p, *q;

	if(nc == NULL)
		return;

	//如果num大于0,表示链表中有大于等于1个节点,所以必须释放.
	if(nc->num > 0)
	{
		//找到管理节点的那保存的链表表头
		p = nc->head;

		//如果节点不为空
		while(p != NULL)
		{
			//先保留p节点的地址
			q = p;
			//p节点向下移动,此时q在p上一个节点位置
			p = p->next;
			//释放p节点的上一个节点
			free(q);
		}
	}

	//链表节点释放完毕,将管理节点的数据清零
	nc->head = NULL;
	nc->num = 0;
	//释放管理节点
	free(nc);
}

void Display(NodeCtrl *nc)
{
	Node*p = NULL;

	if(nc == NULL)
		return;

	printf("Current list has %d date!\n", nc->num);

	//num记录的是节点数量,如果为0,表示是空表
	if(nc->num > 0)
	{
		//找到表头
		p = nc->head;

		//如果节点不为空
		while(p != NULL)
		{
			printf("%d\n", p->date);
			p = p->next;
		}
	}
}
