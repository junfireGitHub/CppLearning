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
	CreateBiTree(T);/*input data:ABC@@DE@G@@F@@@  @��ʾ�ո�
	                �ո�İ������м��ɵģ�����ȷ����ÿ��δ������ӽڵ㶼���NULL*/
	system("pause");
	return 0;
}

