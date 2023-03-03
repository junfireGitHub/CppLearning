
//题目来源，数据结构（严蔚敏）P41
#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct LinkList
{
	int data;
	int order;
	struct LinkList *next;

}LinkList, *pLinkList;

void CreateList(pLinkList &pH, int n)
{
	pH = new LinkList;
	pLinkList pL = pH;
	while (n--)
	{
		pLinkList p = new LinkList;
		cin >> p->data >> p->order;
		pL->next = p;
		pL = p;
	}
	pL->next = NULL;
}

void DisplayList(pLinkList &pH)
{
	pLinkList p = pH->next;
	while (p!=NULL)
	{
		cout << "data:" << p->data << " "
			 << "order:" << p->order <<endl;
		p = p->next;
	}
	cout << "\n";
}

void FreeList(pLinkList &list)
{
	pLinkList pThis = list;
	pLinkList pNext = list->next;
	while (pNext)
	{
		delete pThis;
		pThis = pNext;
		pNext = pThis->next;
	}
	delete pThis;
}
pLinkList& MultinomialAdd(pLinkList &List1, pLinkList &List2)
// 函数通过链表进行多项式相加
{
	pLinkList list1, list2, listRst, p,tmp;
	list1 = List1->next;
	list2 = List2->next;
	p = listRst = new LinkList;
	while (list1 && list2)
	{
		if (list1->order < list2->order)
		{
			tmp = new LinkList;
			tmp->order = list1->order;  tmp->data = list1->data;
			p->next = tmp;
			p = tmp;
			list1 = list1->next;
		}
		else if (list1->order > list2->order)
		{
			tmp = new LinkList;
			tmp->order = list2->order;  tmp->data = list2->data;
			p->next = tmp;
			p = tmp;
			list2 = list2->next;
		}
		else
		{
			tmp = new LinkList;
			tmp->order = list1->order;
			tmp->data = list1->data + list2->data;
			tmp->next = NULL;
			p->next = tmp;
			p = tmp;
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	while (list1)
	{
		tmp = new LinkList;
		tmp->order = list1->order;  tmp->data = list1->data;
		p->next = tmp;
		p = tmp;
		list1 = list1->next;
	}
	while (list2)
	{
		tmp = new LinkList;
		tmp->order = list2->order;  tmp->data = list2->data;
		p->next = tmp;
		p = tmp; 
		list2 = list2->next;
	}
	p->next = NULL;
	return listRst;
}
int main()
{
	pLinkList List1=NULL, List2=NULL,ListRst;
	int n1 , n2;
	cout << "please input the num of term of multinominal one" << endl;
	cin >> n1;
	cout << "please input the coefficient and order of multinominal one" << endl;
	CreateList(List1, n1);
	cout << "please input the num of term of multinominal two" << endl;
	cin >> n2;
	cout << "please input the coefficient and order of multinominal two" << endl;
	CreateList(List2, n2);
	//DisplayList(List1);
	//DisplayList(List2);
	ListRst = MultinomialAdd(List1, List2);
	DisplayList(List1);
	DisplayList(List2);
	DisplayList(ListRst);
	FreeList(List1);
	FreeList(List2);
	FreeList(ListRst);
	system("pause");
	return 0;
}

