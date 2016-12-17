//
// Created by Administrator on 2016/11/7.
//

#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct NOTE
{
	int date;
	NOTE *next;
} NOTE;

class JosephusCircle
{
public:
	void creat_list();
	void Josephus();
private:
	int n;
	int m;
	int s;
	NOTE *head;
};

void JosephusCircle::creat_list()
{
	cout << "请依次输入约瑟夫圏的人数,报数起始位置,报几个数" << endl;
	cin >> n >> s >> m;

	if(0 == m)
	{
		cout << "请注意,报数的个数不能为0!" << endl;
		exit (EXIT_FAILURE);
	}

	NOTE *tail, *p;
	head = (NOTE*)malloc(sizeof(NOTE)); //头结点
	head->next = head;
	tail = head;
	int i;

	for(i = 0; i < n; i++)           //创建单循环链表
	{
		p = (NOTE*)malloc(sizeof(NOTE));
		p->date = (i + 1);
		tail->next = p;
		tail = p;
		p->next = head->next;
	}
}

void JosephusCircle::Josephus()
{
	NOTE*p = head->next;
	NOTE*q = head;                //q指针跟随其后
	int j = 1;

	while(j != s)                 //找到报数点
	{
		p = p->next;
		q = q->next;
		++j;
	}

	while(p != q)
	{
		int i;

		for(i = 0; i < m - 1; i++) //报数出圈
		{
			p = p->next;
			q = q->next;
		}

		cout << p->date << ' ';    //输出前n-1个出圈人的编号
		p = p->next;               //删除结点
		q->next = p;
	}

	cout << p->date;
}                 //输出最后一个出圈人的编号

int main()
{
	JosephusCircle Jose;
	Jose.creat_list();
	cout << "出圈顺序是:" << endl;
	Jose.Josephus();
	cout << endl;
	system("pause");
	return 0;
}
