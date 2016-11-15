//
// Created by Administrator on 2016/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LEN sizeof(struct student)
int n;
struct student
{
	long num;
	float score;
	struct student *next;
};

int main()
{
	struct student *head, *stu;
	long del_num;
	struct student *creat(void);
	void print(struct student * head);
	struct student *del(struct student * head, long num);
	struct student *insert(struct student * head, struct student * stud);

	printf("Please input some records:\n");
	head = creat();
	print(head);
	printf("\nPlease input the delete number:\n");
	scanf("%ld", &del_num);
	while(del_num != 0)
	{
		head = del(head, del_num);
		print(head);
		printf("Please input the deleted number:\n");
		scanf("%ld", &del_num);
	}
	printf("\nPlease input the inserted number:\n");
	stu = (struct student*)malloc(LEN);
	scanf("%ld %f", &stu->num, &stu->score);
	while(stu->num != 0)
	{
		head = insert(head, stu);
		print(head);
		printf("Please input the inserted number:\n");
		stu = (struct student*)malloc(LEN);
		scanf("%ld %f", &stu->num, &stu->score);
	}
	system("pause");
	return 0;
}

struct student *creat(void)
{
	struct student *head, *p1, *p2;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN);
	scanf("%ld %f", &p1->num, &p1->score);
	head = NULL;
	while(p1->num != 0)
	{
		n = n + 1;
		if(1 == n)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}

void print(struct student*head)
{
	struct student *p;
	printf("\nNow,these %d records are:\n", n);
	p = head;
	if(head != NULL)
	{
		do
		{
			printf("%ld %5.1f\n", p->num, p->score);
			p = p->next;
		}
		while(p != NULL);
	}
}

struct student *del(struct student *head, long num)
{
	struct student *p1, *p2;
	if(head == NULL)
	{
		printf("\nSorry,list null!\n");
		return head;
	}
	p1 = head;
	while(num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(num == p1->num)
	{
		if(p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		printf("delete:%ld\n", num);
		n = n - 1;
	}
	else
		printf("%ld not been found!\n", num);

	return head;
}

struct student *insert(struct student*head, struct student*stud)
{
	struct student *p0, *p1, *p2;
	p1 = head;
	p0 = stud;
	if(head = NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while((p1->next != NULL) && (p0->num > p1->num))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p0->num <= p1->num)
		{
			if(head = p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;
	return head;
}
