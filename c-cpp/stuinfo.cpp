//
// Created by Administrator on 2016/11/4.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nvGui
{
	int id;
	char name[100];
	int age;
	char address[100];
	struct nvGui *pre;
	struct nvGui *next;
};


void title();
void MingLingTiShi();
void fenpei();
void printDoubleLianBiao(struct nvGui *head);
void printOneNode(struct nvGui *p);
void changeByMatchID(struct nvGui *head, int id);
void searchNodeByMatchID(struct nvGui *head, int id);
void searchNodeByMatchName(struct nvGui *head, char *findName);
void searchNodeByMatchAge(struct nvGui *head, int age);
void searchNodeByMatchAddress(struct nvGui *head, char *findAddress);
void saveToPC(struct nvGui *head, int *count);
void backUP();
void upsort(struct nvGui *head);
void jiaohuanNodeDate(struct nvGui *p, struct nvGui *q);

struct nvGui *load();
struct nvGui *creat();
struct nvGui *shenQingOneNode();
struct nvGui *insertIntoFirst(struct nvGui *head);
struct nvGui *insertIntoLast(struct nvGui *head);
struct nvGui *insertNodeByMatchID(struct nvGui *head, int id);
struct nvGui *deleteNodeByMatchID(struct nvGui *head, int id);

struct nvGui *getLastNode(struct nvGui *head);
struct nvGui *deleteFirstNode(struct nvGui *head);


int tongJiDoubleLianBiao(struct nvGui *head);


int main()
{
	title();
	MingLingTiShi();
	fenpei();
	return 0;
}

void title()
{
	printf("\n\t\t*******************************************");
	printf("\n\t\t***********档案管理系统（c语言）***********");
	printf("\n\t\t*******************************************");
	printf("\n\t\t                               作者：文健蔚");
	printf("\n\t\t                                  2014.2.21");
	printf("\n");
}

void MingLingTiShi()
{
	printf("\n\t\t\t         内置命令\n");
	printf("\t\t   ------------------------------------\n");
	printf("\t\t   |   数字命令    |     功能描述     |\n");
	printf("\t\t   ------------------------------------\n");
	printf("\t\t   |      -1       >>    退出系统     |\n");
	printf("\t\t   |       0       >>    显示命令     |\n");
	printf("\t\t   |       1       >>    加载数据     |\n");
	printf("\t\t   |       2       >>    创建数据     |\n");
	printf("\t\t   |       3       >>    添加数据     |\n");
	printf("\t\t   |       4       >>    删除数据     |\n");
	printf("\t\t   |       5       >>    修改数据     |\n");
	printf("\t\t   |       6       >>    查询数据     |\n");
	printf("\t\t   |       7       >>    显示数据     |\n");
	printf("\t\t   |       8       >>    保存数据     |\n");
	printf("\t\t   |       9       >>    备份数据     |\n");
	printf("\t\t   |      10       >>    排    序     |\n");
	printf("\t\t   ------------------------------------\n");
}

void fenpei()//通过不同的命令选择相应的函数
{
	struct nvGui *head = NULL;
	int i = -10;
	int getID = 0;
	int mode = 0;
	char findstr[100];
	int count = 0;
	printf("\n输入数据命令->");
	scanf("%d", &i);
	//printf("i=%d\n",i);

	while(i > -1 || i < 11)
	{
		switch(i)
		{
			case 0:
				//printf("i=%d\n",i);
				MingLingTiShi();
				break;

			case 1:
				//printf("i=%d\n",i);
				head = load();
				printDoubleLianBiao(head);
				break;

			case 2:
				//printf("i=%d\n",i);
				printf("创建数据\n");
				head = creat();
				printDoubleLianBiao(head);
				break;

			case 3:
				//printf("i=%d\n",i);
				printf("添加数据\n");
				printf("选择添加模式：\n 300:从头添加    |    301:从尾添加   |    302：匹配添加于节点前\n");
				scanf("%d", &mode);

				if(mode == 300)
				{
					head = insertIntoFirst(head);
				}
				else if(mode == 301)
				{
					head = insertIntoLast(head);
				}
				else if(mode == 302)
				{
					printf("输入一个ID->");
					scanf("%d", &getID);
					head = insertNodeByMatchID(head, getID);
				}
				else
				{
					printf("无效命令\n");
				}

				printDoubleLianBiao(head);
				break;

			case 4:
				//printf("i=%d\n",i);
				printf("删除记录\n");
				printf("输入想要删除的ID->");
				scanf("%d", &getID);
				head = deleteNodeByMatchID(head, getID);
				printDoubleLianBiao(head);
				break;

			case 5:
				//printf("i=%d\n",i);
				printf("修改记录\n");
				printf("输入想要修改的ID->");
				scanf("%d", &getID);
				changeByMatchID(head, getID);
				printDoubleLianBiao(head);
				break;

			case 6:
				//printf("i=%d\n",i);
				printf("查询数据\n");
				printf("选择查询模式：\n 600:ID匹配    |    601:姓名匹配   |    602：年龄匹配   |    603:地址匹配\n");
				scanf("%d", &mode);

				if(mode == 600)
				{
					printf("输入一个ID->");
					scanf("%d", &getID);
					searchNodeByMatchID(head, getID);
				}
				else if(mode == 601)
				{
					printf("输入一个name->");
					scanf("%s", findstr);
					searchNodeByMatchName(head, findstr);
				}
				else if(mode == 602)
				{
					printf("输入一个age->");
					scanf("%d", &getID);
					searchNodeByMatchAge(head, getID);
				}
				else if(mode == 603)
				{
					printf("输入一个address->");
					scanf("%s", findstr);
					searchNodeByMatchAddress(head, findstr);
				}
				else
				{
					printf("无效命令\n");
				}

				break;

			case 7:
				//printf("i=%d\n",i);
				printDoubleLianBiao(head);
				break;

			case 8:
				//printf("i=%d\n",i);
				printf("保存记录\n");
				count = tongJiDoubleLianBiao(head);
				saveToPC(head, &count);
				break;

			case 9:
				//printf("i=%d\n",i);
				backUP();
				break;

			case 10:
				//printf("i=%d\n",i);
				upsort(head);
				break;

			default:
				printf("无效命令\n");
		}

		printf("\n输入数字命令->");
		scanf("%d", &i);

		if(-1 == i)
		{
			break;
		}
	}
}

struct nvGui *load()
{
	struct nvGui *head = NULL;
	struct nvGui *p = NULL;
	struct nvGui *q = NULL;
	int flag = 1;
	int panduan = 100;
	FILE *sourceFile = NULL;
	char name[100] = "lizhijd.dat";
	sourceFile = fopen(name, "r");

	while(sourceFile == NULL)
	{
		printf("源文件不存在\n");
		sourceFile = fopen(name, "r");
	}

	p = (struct nvGui *)malloc(sizeof(struct nvGui));

	if(!p)
	{
		printf("申请内存失败!\n");
		exit(-1);
	}

	panduan = fscanf(sourceFile, "%d", &(p->id));

	if(panduan == 1)
	{
		fscanf(sourceFile, "%s", (p->name));
		fscanf(sourceFile, "%d", &(p->age));
		fscanf(sourceFile, "%s", (p->address));
		p->pre = NULL;
		p->next = NULL;
		head = p;
		q = p;

		while(flag == 1)
		{
			p = (struct nvGui *)malloc(sizeof(struct nvGui));

			if(!p)
			{
				printf("申请内存失败!\n");
				exit(-1);
			}

			panduan = fscanf(sourceFile, "%d", &(p->id));

			if(panduan == 1)
			{
				fscanf(sourceFile, "%s", (p->name));
				fscanf(sourceFile, "%d", &(p->age));
				fscanf(sourceFile, "%s", (p->address));
				p->pre = NULL;
				p->next = NULL;
				q->next = p;
				p->pre = q;
				q = p;
			}
			else
			{
				flag = 0;
			}
		}
	}

	printf("文件加载成功...\n");
	return head;
}

struct nvGui *creat()
{
	struct nvGui *lianBiaoTou;
	struct nvGui *p;
	struct nvGui *q;
	int i;
	lianBiaoTou = shenQingOneNode();
	p = lianBiaoTou;
	q = lianBiaoTou;
	printf("1：继续          2：停止\n");
	scanf("%d", &i);

	while(i == 1)
	{
		p = shenQingOneNode();
		q->next = p;
		p->pre = q;
		q = p;
		printf("1：继续          2：停止\n");
		scanf("%d", &i);

		if(i == 2)
		{
			break;
		}
	}

	return lianBiaoTou;
}

struct nvGui *shenQingOneNode()
{
	struct nvGui *p;
	p = (struct nvGui *)malloc(sizeof(struct nvGui));

	if(p == NULL)
	{
		printf("fail");
		exit(-1);
	}

	printf("请输入一条记录的内容:\n");
	printf("序号->");
	scanf("%d", &(p->id));
	printf("姓名->");
	scanf("%s", p->name);
	printf("年龄->");
	scanf("%d", &(p->age));
	printf("地址->");
	scanf("%s", p->address);
	p->pre = NULL;
	p->next = NULL;
	return p;
}

void printDoubleLianBiao(struct nvGui *head)
{
	struct nvGui *p;
	int count = 0;
	p = head;
	printf("\n\n\t\t\t 档案信息表\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	if(p == NULL)
		printf("\t|                       空记录                    |\n");

	while(p != NULL)
	{
		count++;
		printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);
		p = p->next;
	}

	printf("\t---------------------------------------------------\n");
	printf("\t\t\t\t    共有 %d 条记录----------\n", count);
}

struct nvGui *insertIntoFirst(struct nvGui *head)
{
	struct nvGui *p;
	printf("从头添加\n");
	p = shenQingOneNode();

	if(head != NULL)
	{
		//printf("里面");
		p->next = head;
		head->pre = p;
		return p;
	}
	else
		return p;

	return p;
}

struct nvGui *getLastNode(struct nvGui *head)
{
	struct nvGui *p;
	p = head;

	if(p == NULL)
		return NULL;
	else
	{
		while(p->next != NULL)
			p = p->next;
	}

	return p;
}

struct nvGui *insertIntoLast(struct nvGui *head)
{
	struct nvGui *p;
	struct nvGui *m;
	printf("从尾添加\n");
	p = head;
	m = shenQingOneNode();
	p = getLastNode(head);

	if(p != NULL)
	{
		p->next = m;
		m->pre = p;
		return head;
	}
	else
	{
		return m;
	}
}

struct nvGui *insertNodeByMatchID(struct nvGui *head, int id)
{
	struct nvGui *p;
	struct nvGui *m;
	p = head;

	while(p != NULL)
	{
		if(p->id == id)
			break;

		p = p->next;
	}

	if(p == NULL)
	{
		printf("没有匹配的记录\n");
	}
	else
	{
		if(p->pre == NULL)
		{
			head = insertIntoFirst(head);
		}
		else
		{
			m = shenQingOneNode();
			m->next = p;
			p->pre->next = m;
			m->pre = p->pre;
			p->pre = m;
		}
	}

	return head;
}

struct nvGui *deleteFirstNode(struct nvGui *head)
{
	struct nvGui *p;

	if(head->next == NULL)
	{
		free(head);
		return NULL;
	}

	p = head;
	head = head->next;
	head->pre = NULL;
	free(p);
	return head;
}

struct nvGui *deleteNodeByMatchID(struct nvGui *head, int id)
{
	struct nvGui *p;
	p = head;

	while(p != NULL)
	{
		if(p->id == id)
			break;

		p = p->next;
	}

	if(p == NULL)
	{
		printf("没有匹配的数据\n");
	}
	else
	{
		if(p->pre == NULL)
		{
			head = deleteFirstNode(head);
		}
		else if(p->next == NULL)
		{
			p->pre->next = NULL;
			free(p);
		}
		else
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
		}
	}

	return head;
}

void changeByMatchID(struct nvGui *head, int id)
{
	struct nvGui *p;
	p = head;

	while(p != NULL)
	{
		if(p->id == id)
		{
			printOneNode(p);
			printf("输入新信息:\n");
			printf("新序号->");
			scanf("%d", &(p->id));
			printf("新名字->");
			scanf("%s", (p->name));
			printf("新年龄->");
			scanf("%d", &(p->age));
			printf("新地址->");
			scanf("%s", (p->address));
		}

		p = p->next;
	}
}

void printOneNode(struct nvGui *p)
{
	printf("\n\n\t\t\t 该条记录内容\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	if(p != NULL)
		printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);

	printf("\t---------------------------------------------------\n");
}

void searchNodeByMatchID(struct nvGui *head, int id)
{
	struct nvGui *p;
	p = head;
	printf("\n\n\t\t\t 该条记录内容\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	while(p != NULL)
	{
		if(p->id == id)
		{
			printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);
		}

		p = p->next;
	}

	printf("\t---------------------------------------------------\n");
}

void searchNodeByMatchName(struct nvGui *head, char *findName)
{
	struct nvGui *p;
	p = head;
	printf("\n\n\t\t\t 该条记录内容\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	while(p != NULL)
	{
		if(!strcmp(p->name, findName))
		{
			printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);
		}

		p = p->next;
	}

	printf("\t---------------------------------------------------\n");
}

void searchNodeByMatchAge(struct nvGui *head, int age)
{
	struct nvGui *p;
	p = head;
	printf("\n\n\t\t\t 该条记录内容\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	while(p != NULL)
	{
		if(p->age == age)
		{
			printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);
		}

		p = p->next;
	}

	printf("\t---------------------------------------------------\n");
}

void searchNodeByMatchAddress(struct nvGui *head, char *findAddress)
{
	struct nvGui *p;
	p = head;
	printf("\n\n\t\t\t 该条记录内容\n");
	printf("\n\t---------------------------------------------------\n");
	printf("\t|    序号\t姓名\t\t年龄\t  地址    |\n");
	printf("\t---------------------------------------------------\n");

	while(p != NULL)
	{
		if(!strcmp(p->address, findAddress))
		{
			printf("\t|     %-5d\t%-10s\t%-5d\t  %-8s|\n", p->id, p->name, p->age, p->address);
		}

		p = p->next;
	}

	printf("\t---------------------------------------------------\n");
}

int tongJiDoubleLianBiao(struct nvGui *head)
{
	struct nvGui *p;
	int count = 0;
	p = head;

	while(p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

void saveToPC(struct nvGui *head, int *count)
{
	struct nvGui *p = NULL;
	FILE *outFilePrinter = NULL;
	char out_name[100] = "lizhijd.dat";
	int i;
	p = head;
	outFilePrinter = fopen(out_name, "w");

	for(i = 0; i < (*count); i++)
	{
		fprintf(outFilePrinter, "%-5d\t%-10s\t%-5d\t  %-8s\n", p->id, p->name, p->age, p->address);
		p = p->next;
	}

	fprintf(outFilePrinter, "----------------------------------------------------\n");
	fprintf(outFilePrinter, "\n\t\t  共有 %d 条记录！\n\n\n", *count);
	fprintf(outFilePrinter, "\t\t\t\t\t档案管理系统（c语言）\n");
	fprintf(outFilePrinter, "\t\t\t\t\t        作者：文健蔚\n");
	fprintf(outFilePrinter, "\t\t\t\t\t           2014.3.22\n");
	fclose(outFilePrinter);
	printf("\n\n\t\t\t恭喜你,保存成功！\n");
}

void backUP()
{
	char ch;
	char source[20] = "lizhijd.dat", end[200] = "lizhijd.bak";
	FILE *sourceFile;
	FILE *endFile;
	sourceFile = fopen(source, "r");

	if(sourceFile == NULL)
	{
		printf("%s文件不存在", source);
		exit(0);
	}

	endFile = fopen(end, "w");

	if(endFile == NULL)
	{
		printf("备份失败");
		exit(0);
	}

	for(ch = getc(sourceFile); ch != EOF; ch = getc(sourceFile))
	{
		putc(ch, endFile);
	}

	fclose(sourceFile);
	fclose(endFile);
	printf("\n\n\t\t\t备份成功！！！\n");
}

void upsort(struct nvGui *head)
{
	struct nvGui *p;
	struct nvGui *q;
	printf("ok");

	for(p = head; p->next != NULL; p = p->next)
	{
		for(q = p->next; q != NULL; q = q->next)
		{
			if(p->id > q->id)
			{
				jiaohuanNodeDate(p, q);
			}
		}
	}
}

void jiaohuanNodeDate(struct nvGui *p, struct nvGui *q)
{
	int id;
	char name[100];
	int age;
	char address[100];
	id = p->id;
	p->id = q->id;
	q->id = id;
	strcpy(name, p->name);
	strcpy(p->name, q->name);
	strcpy(q->name, name);
	age = p->age;
	p->age = q->age;
	q->age = age;
	strcpy(address, p->address);
	strcpy(p->address, q->address);
	strcpy(q->address, address);
}
