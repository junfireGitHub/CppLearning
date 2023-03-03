#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

/*对于堆来说，任一位置i上的元素，其左儿子在位置2i，右儿子在左儿子后的
单元（2i+1）中，它的父亲则在位置（i/2）（向下取整）上*/

void HeapAdjust(int list[], int root, int n)
{
	int child, rootkey;
	rootkey = list[root];
	child = 2 * root;
	while (child <= n)
	{
		if (child < n && list[child] < list[child + 1]) //这里是个最大堆，最小堆需改为>
			child++;       /*为什么需要这步？试想 65 24 78，如果没有这步，
						   则65 与 24 比较之后不会交换，
		                   但事实上78>65,不满足最大堆的条件*/
						   
		/*if else 里是否可以用交换*/
		if (rootkey>list[child])
			break;
		else{
			list[child / 2] = list[child];
			child *= 2;
		}
	}
	list[child / 2] = rootkey;
}

void HeapSort(int a[],int length)
{
	int tmp;

	/*bulid a heap*/
	for (int i = length / 2; i>0; --i)
		HeapAdjust(a, i, length);

	/*sort*/
	for (int i = length; i > 1; --i)
	{
		swap(a[i], a[1]);
		HeapAdjust(a, 1, i - 1);
	}
}

int main()
{
	const int length = 11;
	int a[length] = { 0, 20,18,22,24,45,23,56,78,23,90};
	HeapSort(a,length-1);
	system("pause");
	return 0;
}

//int n = 20;
//srand(time(NULL));
//a.clear();
//a.push_back(-1);
//while (n--){
//	a.push_back(rand() % 30);
//}