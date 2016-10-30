//
// Created by Administrator on 2016/10/30.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct people			/*定义结构体，存放联系人信息*/
{
	char name[8];		/*姓名*/
	char address[50];	/*地址*/
	char post[30];
	char post_before[20];
	char post_after[10];	/*邮箱*/
	char phone[5][30];
	int phonenum;		/*电话*/

	struct people*next;	/*下个结点*/
};
char email[10][18] = {"@gmail.com", "@yahoo.com", "@163.com", "@googlemail.com", "@sohu.com", "@qq.com", "@sogou.com", "@candel.co.jp", " @126.com ", "@sina.com"};

typedef struct people pe;/*定义pe为结构体指针*/
pe*head = NULL;	/*定义全局指针变量*/
void menu();	/*显示菜单*/
void look();	/*查找联系人*/
void display();	/*显示全部联系人*/
void add();		/*添加联系人*/
void modify();	/*修改联系人*/
void del();		/*删除联系人*/
void save();	/*保存*/
void save2();
void open();	/*打开*/
void jixu(int x);
pe *find();

void name_validity(pe *p);
void address_validity(pe *p);
void post_validity(pe *p) ;
void phone_validity(pe *p, int a);
void range(char *a[], int n);




void range(char *ptr[], int n)
{
	int i, j;
	char *temp = NULL;

	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(strcmp(ptr[j], ptr[i]) < 0)
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

void name_validity(pe *p)
{
	int i;
	int flag = 1;

	do
	{
		scanf("%s", p->name);

		for(i = 0; p->name[i] != '\0'; i++)
		{
			if((p->name[i]) < 0)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				goto a;
			}
		}

		goto b;
		a:
		printf("wrong,please input the true name\n");
		b:
		;
	}
	while(flag == 0);
}

void address_validity(pe *p)
{
	int i;
	int flag = 1;

	do
	{
		scanf("%s", p->address);

		for(i = 0; p->address[i] != '\0'; i++)
		{
			if(p->address[i] < 0)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				goto a;
			}
		}

		goto b;
		a:
		{
			printf("wrong,please input the true address\n");
		}
		b:
		;
	}
	while(flag == 0);
}

void post_validity(pe *p)
{
	int i = 0, j = 0;
	int flag;

	do
	{
		flag = 1;
		scanf("%s", p->post);

		for(i = 0; (p->post[i] != '@') && (p->post[i] != '\0') && (i < 20); i++)
		{
			p->post_before[i] = p->post[i];
		}

		if(p->post[i] == '\0')
		{
			flag = 0;
			goto a;
		}

		for(j = 0; p->post[i] != '\0'; i++, j++)
		{
			p->post_after[j] = p->post[i];
		}

		p->post[i] = '\0';

		for(i = 0; i < 10; i++)
		{
			if((strncmp(p->post_after, email[i], j)) == 0)
			{
				goto b;
			}
		}

		a:
		{
			printf("wrong,please input the true post\n");
		}
		b:
		;
	}
	while(flag == 0);
}

void phone_validity(pe *p, int a)
{
	int i, j;
	int flag = 1;

	for(i = 0; i < a; i++)
	{
		do
		{
			flag = 1;
			scanf("%s", p->phone[i]);

			if(p->phone[i][0] == '0')
			{
				flag = 0;
				goto a;
			}

			for(j = 1; j <= 10; j++)
			{
				if(p->phone[i][j] > 48 || p->phone[i][j] < 57);
				else
				{
					flag = 0;
					goto a;
				}
			}

			if(p->phone[i][j] != '\0')
			{
				flag = 0;
				goto a;
			}

			goto b;
			a:
			{
				printf("wrong,please input the true %dst phonenumber\n", i);
			}
			b:
			;
		}
		while(flag == 0);
	}
}


/*显示菜单*/
void menu()
{
	printf("\n\t\t\t  *****************************\n\n");
	printf("\t\t\t\t   1.添加联系人\n");
	printf("\t\t\t\t   2.修改联系人\n");
	printf("\t\t\t\t   3.删除联系人\n");
	printf("\t\t\t\t   4.查找联系人\n");
	printf("\t\t\t\t   5.全部联系人\n");
	printf("\t\t\t\t   0.保存并退出\n");
	printf("\n\t\t\t  *****************************\n\n");
	printf("\t\t\t\t     请选择\n");
}

/*添加联系人*/
void add()
{
	pe *p1 = NULL, *p2 = NULL;
	char c;
	p1 = (pe*)malloc(sizeof(pe));	/*动态内存申请*/
	printf("\t\t\t\t请输入姓名：");
	name_validity(p1);
	printf("\t\t\t\t请输入地址：");
	address_validity(p1);
	printf("\t\t\t\t请输入邮箱：");
	post_validity(p1) ;
	printf("\t\t\t\t请输入电话个数：");
	scanf("%d%c", &(p1->phonenum), &c);
	printf("\t\t\t\t请输入电话：");
	phone_validity(p1, p1->phonenum);
	p1->next = NULL;	/*表明是个新链表，给表头分配空间，增加结点*/

	if(NULL == head)
	{
		head = (pe*)malloc(sizeof(pe));
		head->next = p1;
	}
	else
	{
		for(p2 = head; p2->next != NULL; p2 = p2->next);

		p2->next = p1;
	}
}

/*查找联系人*/
void look()
{
	pe*p = find();
	int i;

	if(NULL == p)
		printf("\a\t\t\t\t没有找到该联系人！\n");
	else
		printf("\t\t\t\t查找的联系人为\n\n\t\t\t\t姓名：%s\n\t\t\t\t地址:%s\n\t\t\t\t邮编:%s\n\t\t\t\tQQ:%s\n", p->next->name, p->next->address, p->next->post);

	printf("\t\t\t\t电话:\n");

	for(i = 0; i < (p->phonenum); i++)
	{
		printf("\t\t\t\t\t%s\n", p->phone[i]);
	}
}
pe*find()
{
	char name[20];	/*临时姓名数组*/
	pe *p = NULL;
	printf("\t\t\t\t请输入姓名：");
	scanf("%s", name);

	if(head == NULL)
	{
		printf("\a\t\t\t\t电话簿中没有记录！\n");
		return NULL;
	}

	for(p = head; p->next != NULL; p = p->next)
		if(!strcmp(p->next->name, name))
			return p;

	return NULL;
}

/*显示全部联系人*/
void display()
{
	pe *p = NULL;
	int i;

	if(head == NULL)
	{
		printf("\a\t\t\t\t电话簿中没有记录！\n\n");
		return;
	}

	for(p = head->next; p != NULL; p = p->next)
	{
		printf("%s\t%s\t%s\t", p->name, p->address, p->post);
		printf("\n");

		for(i = 0; i < (p->phonenum); i++)
		{
			printf("\t%s\n", p->phone[i]);
		}
	}
}

/*修改联系人*/
void modify()
{
	int q;
	pe*p = find();

	if(NULL == p)
		printf("\a\t\t\t\t该联系人不存在!\n\n");
	else
	{
		printf("\n\t\t\t\t要修改的项目!\n\n\t\t\t\t1.姓名:%s\n\t\t\t\t2.地址:%s\n\t\t\t\t3.邮编:%s\n\t\t\t\t4.电话%s\n\n\n", p->next->name, p->next->address, p->next->post, p->next->phone);
		scanf("%d", &q);

		switch(q)
		{
			case 1:
				printf("\t\t\t\t请输入新的姓名：");
				scanf("%s", p->next->name);
				break;

			case 2:
				printf("\t\t\t\t请输入新的地址：");
				scanf("%s", p->next->address);
				break;

			case 3:
				printf("\t\t\t\t请输入新的邮编：");
				scanf("%s", p->next->post);
				break;

			case 4:
				printf("\t\t\t\t请输入新的电话：");
				scanf("%s", p->next->phone);
				p->next->next = NULL;
				break;

			default:
				printf("数据错误！请重新输入！");
		}
	}
}

/*删除联系人*/
void del()
{
	int i;
	pe*temp = NULL;
	pe*p = find();

	if(NULL == p)
		printf("\a\t\t\t\t该联系人不存在!\n\n");
	else
	{
		printf("\t\t\t\t要删除的联系人!\n\n\t\t\t\t姓名：%s\n\t\t\t\t地址:%s\n\t\t\t\t邮编:%s：%s\n", p->next->name, p->next->address, p->next->post);
		printf("\t\t\t\t电话：\n");

		for(i = 0; i < (p->phonenum); i++)
		{
			printf("\t\t\t\t%s\n", p->phone[i]);
		}

		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}



/*保存，输出信息到文件，并释放链表空间*/
void save()
{
	int i;
	pe*p = NULL;
	FILE*fp;
	char*filename = "people.txt";

	if(head == NULL)
	{
		printf("\a\n\t\t\t\t   无内容保存！\n");
	}
	else
		p = head->next;

	/*出错检测*/
	if((fp = fopen(filename, "w")) == NULL)
	{
		printf("\n\a\t\t\t\t文件打开失败！\n");
		return;
	}

	while(p != NULL)
	{
		fprintf(fp, "%s\t %s\t %s\t %d\t \n", p->name, p->address, p->post, p->phonenum); /*\t用于将写入的文本隔开*/

		for(i = 0; i < (p->phonenum); i++)
		{
			fprintf(fp, "%s\t", p->phone[i]);
		}

		p = p->next;
	}

	printf("\t\t\t\t    保存完毕！\n");
	/*释放链表空间*/
	fclose(fp);
}


void save2()
{
	pe*p = NULL;
	FILE*fp;
	char*filename = "delpeople.txt";

	if(head == NULL)
	{
		printf("\a\n\t\t\t\t   无内容保存！\n");
	}
	else
		p = head->next;

	/*出错检测*/
	if((fp = fopen(filename, "w")) == NULL)
	{
		printf("\n\a\t\t\t\t文件打开失败！\n");
		return;
	}

	while(p != NULL)
	{
		fprintf(fp, "%s\t %s\t %s\t%s\t\n", p->name, p->address, p->post, p->phone); /*\t用于将写入的文本隔开*/
		p = p->next;
	}

	printf("\t\t\t\t    保存完毕！\n");
	/*释放链表空间*/
	fclose(fp);
}


/*读取文件信息到链表*/
void open()
{
	FILE*fp;
	int i;
	pe*p1 = NULL, *p2 = NULL, *temp = NULL;

	if((fp = fopen("people.txt", "r")) == NULL) /*打开文件*/
	{
		printf("\t\t\t\t   电话簿为空！\n");
		return;
	}

	head = (pe*)malloc(sizeof(pe));
	head->next = NULL;
	temp = p2 = head;

	while(!feof(fp))/*循环读取文件信息*/
	{
		p1 = (pe*)malloc(sizeof(pe));
		temp = p2;
		p2->next = p1;
		p2 = p1;
		fscanf(fp, "%s%s%s", p1->name, p1->address, p1->post); /*读取文件信息*/

		for(i = 0; i < (p1->phonenum); i++)
		{
			fscanf(fp, "%s", p1->phone[i]);
		}
	}

	temp->next = NULL;
	fclose(fp);/*关闭文件*/
}


void jixu(int x)
{
	int w;

	do
	{
		printf("\n\t\t\t\t是否继续？\n\n");
		printf("\t\t\t\t1.是\n\n\t\t\t\t2.否\n\t\t\t\t");
		scanf("%d", &w);

		if(w == 1)
		{
			if(x == '1')
				add();

			if(x == '2')
				modify();

			if(x == '3')
				del();
		}
		else if(w = 2)
		{
			break;
		}
		else
		{
			printf("输入错误！请重新输入！");
		}
	}
	while(w == 1);
}

int main()
{
	char x;
	int judge = 0;	/*创建，并设置退出循环条件为假*/
	open();			/*输出文件信息到链表*/

	while(judge == 0)	/*程序循环*/
	{
		menu();		/*显示菜单*/
		scanf("%s", &x);

		switch(x)
		{
			case'0':
				judge = 1;	/*退出条件为真，退出并保存联系人信息*/
				save();
				break;

			case'1':
				system("cls");/*清屏*/
				printf("\n\t\t\t\t添加联系人\n\n");
				add();		/*添加联系人*/
				save();
				jixu(x);
				break;

			case'2':
				system("cls");/*清屏*/
				save2();
				printf("\n\t\t\t\t修改联系人\n\n");
				modify();	/*修改联系人*/
				save();
				jixu(x);
				break;

			case'3':
				system("cls");/*清屏*/
				save2();
				printf("\n\t\t\t\t删除联系人\n\n");
				del();		/*删除联系人*/
				jixu(x);
				break;

			case'4':
				system("cls");/*清屏*/
				printf("\n\t\t\t\t查找联系人\n\n");
				look();		/*查找联系人*/
				break;

			case'5':
				system("cls");/*清屏*/
				printf("\n\t\t\t\t所有联系人\n\n");
				display();	/*显示所有联系人*/
				break;

			default:
				printf("\a\t\t\t\t    输入错误！\n");/*用声音、文本提示错误输入*/
				break;
		}
	}

	return 0;
}
