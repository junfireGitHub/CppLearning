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
	QueuePtr front; // ��ͷָ��
	QueuePtr rear;  // ��βָ��
}LinkQueue;

bool InitQueue(LinkQueue &Q)
// ����һ���ն���Q
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return true;
}

bool DestroyQueue(LinkQueue &Q)
//���ٶ���Q
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
//����Ԫ��eΪQ���µĶ�βԪ��
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
//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	if (Q.rear == Q.front) return false;
	/* ���ﲻ�ǽ�Q.frontɾ������������ָ��Ķ�ͷԪ��*/
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

