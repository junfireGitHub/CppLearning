
/*输入前序遍历序列{1,2,4,7,3,5,6,8}和
 *中序遍历序列{4,7,2,1,5,3,8,6}，
 *来重建原始的二叉树，并验证*/

#include"HeaderLib.h"
using namespace std;

struct BTree{
	int val;
	BTree *pLeft;
	BTree *pRight;
	BTree(){
		val = 0;
		pLeft = nullptr;
		pRight = nullptr;
	}
};

BTree* construct(int *ps, int *pe, int *is, int *ie){
	BTree *bt = new BTree();
	int rootVal = ps[0];
	bt->val = rootVal;

	if (ps == pe)
		return bt;

	int *pRoot = is;
	while (pRoot <= ie && *pRoot != rootVal)
		pRoot++;

	int len = pRoot - is;
	int leftLen = pRoot - is;
	if (leftLen>0)
		bt->pLeft = construct(ps + 1, ps + len, is, pRoot - 1);
	int rightLen = ie - pRoot;
	if (rightLen>0)
		bt->pRight = construct(ps + len + 1, pe, pRoot + 1, ie);

	return bt;
}

void preTraverse(BTree *bt){
	if (bt == nullptr)
		return;
	cout << bt->val << " ";
	preTraverse(bt->pLeft);
	preTraverse(bt->pRight);
}

void inTraverse(BTree *bt){
	if (bt == nullptr)
		return;
	inTraverse(bt->pLeft);
	cout << bt->val << " ";
	inTraverse(bt->pRight);
}

void bTraverse(BTree *bt){
	if (bt == nullptr)
		return;
	bTraverse(bt->pLeft);
	bTraverse(bt->pRight);
	cout << bt->val << " ";
}


int main(){
	int preArr[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inArr[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int n = 8;
	BTree *p = construct(&preArr[0], &preArr[0] + 7, &inArr[0], &inArr[0] + 7);
	preTraverse(p);
	cout << endl;
	inTraverse(p);
	cout << endl;
	bTraverse(p);
	cout << endl;
	return 0;
}
