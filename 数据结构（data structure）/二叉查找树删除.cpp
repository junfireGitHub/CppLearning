#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct BTree{
	int data;
	BTree *lchild;
	BTree *rchild;
}BTree, *pBinTree;

void deleteNode(pBinTree &p){

	if (!p->lchild){
		pBinTree q = p;
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild){
		pBinTree q = p;
		p = p->lchild;
		free(q);
	}
	else{
		pBinTree q = p;
		pBinTree s = q->lchild;
		while (s->rchild) { q = s; s = s->rchild; }
		p->data = s->data;
		if (q != p){
			q->rchild = s->lchild;
		}
		else{
			q->lchild = s->lchild;
		}
		delete s;
	}
}

void cstBTree(pBinTree &pH, int data){
	if (!pH){ 
		pH = new BTree({ data, NULL, NULL });
		return;
	}
	BTree *p = pH;
	while (1){
		if (data > p->data){
			if (!p->rchild){
				p->rchild = new BTree({ data, NULL, NULL });
				return;
			}
			else{
				p = p->rchild;
			}
		}
		else if (data < p->data){
			if (!p->lchild){
				p->lchild = new BTree({ data, NULL, NULL });
				return;
			}
			else{
				p = p->lchild;
			}
		}
		else{
			return;
		}
	}
}

int main(){
	int a[10] = { 45, 24, 53, 45, 12, 24, 90, 26, 25, 29 };
	BTree *p = NULL;
	for (int i = 0; i < 10; i++){
		cstBTree(p, a[i]);
	}
	deleteNode(p);
	return 0;
}