#include"stdio.h"
#include"string.h"
#include"math.h"
#include"stdlib.h"

int main()
{
	char test;
	typedef struct node
	{
		char name[10];
		int height;
		struct node *next;    /*要实现双向链表，可以再多定义一个指针before，从后面指向前面*/
	}link;

	link *first=NULL;
	link *current=NULL;
	link *previous=NULL;      /* initialize*/

	while(1)
	{
		printf("\ndo you want to input data ?(y or n):");
		scanf(" %c",&test); // there is a blank before %c,because we click the enter when we saw printf("please input height(cm): ");
		if(test=='n') break;
		current=(struct node*)(malloc(sizeof(struct node)));
		if(current==NULL)
		{
			printf("内存分配失败");
		    exit(0);
		}
		printf("please input name: ");
		scanf("%s",current->name);
		printf("please input height(cm): ");
		scanf("%d",&current->height);       /*symbol '&' shouldn't be forgotten */
		if(first==NULL)
			first=current;                  /*in order to find the head of linked list when we need to ouput the data*/
		if(previous!=NULL)
			previous->next=current;         /*is equavilent to current->next=current(new node)*/
		previous=current;	
		current->next=NULL;                 /*(in case it's the last)this code can be used as the end of the linked list*/
	}
	current=first;       /*that's the reason why write the code first=code. get the head*/
	while(current!=NULL) /*that's the reason why write the code current->nex=NULL. get the end*/
	{
		printf("name: %s\n",current->name);
		printf("height: %d\n",current->height);
		previous=current;      /*save the pointer,so we can free the memeory*/  
		current=current->next;
		free(previous);        /*free the memory node by node*/    
	}
   /*对于上面的这段代码使用
	for(current=first; current!=NULL; current=current=>next)
	更好。*/
	return 0;
}