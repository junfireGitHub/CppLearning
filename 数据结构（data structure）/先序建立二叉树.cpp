#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;

}BiTNode,*BiTree;

bool flag = false;
bool CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') flag = true;
	if (ch == ' ' || flag) {
		T = NULL;
		return true;
	}
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if (!T) exit(OVERFLOW);
	T->data = ch;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
	return true;
}

int main()
{
	BiTree T = NULL;
	CreateBiTree(T);/*input data:ABC@@DE@G@@F@@@  @表示空格，
	                空格的安置是有技巧的，这样确保了每个未分配的子节点都变成NULL*/
	system("pause");
	return 0;
}

