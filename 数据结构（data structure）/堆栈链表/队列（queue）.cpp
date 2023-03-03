#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front; // 队头指针
	QueuePtr rear;  // 队尾指针
}LinkQueue;

bool InitQueue(LinkQueue &Q)
// 构造一个空队列Q
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return true;
}

bool DestroyQueue(LinkQueue &Q)
//销毁队列Q
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return true;
}

bool EnQueue(LinkQueue &Q, QElemType e)
//插入元素e为Q的新的队尾元素
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

bool DeQueue(LinkQueue &Q, QElemType &e)
//若队列不空，则删除Q的对头元素，用e返回其值
{
	if (Q.rear == Q.front) return false;
	/* 这里不是将Q.front删除，而是其所指向的队头元素*/
	QueuePtr p = Q.front->next; 
	e = Q.front->data;
	Q.front ->next = p->next;
	free(p); 
	return true;
}

int main()
{
	LinkQueue Q;
	InitQueue(Q);
	for (int i = 0; i < 20; i++)
		EnQueue(Q, i);
	int j = 10,tmp;
	while (j--)
		DeQueue(Q, tmp);

	DestroyQueue(Q);
	system("pause");
	return 0;
}

