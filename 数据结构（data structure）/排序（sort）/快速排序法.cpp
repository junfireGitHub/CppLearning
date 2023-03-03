#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

void qsort(int a[], int left, int right)
{
	if (left >= right) return;

	int pivot = a[left];//这里枢纽元可以不选为第一个元素，最好的枢纽元的选取见数据结构与算法分析C++描述
	int i=left, j=right;
	while (i<j){
		/*设想全相同的一个数组，如果这里没有等号，则i,j不移动*/	
		while (i < j&&a[j] >= pivot) j--; //需要i<j条件是为了防止跃出数组的边界
		a[i] = a[j];                      
		while (i < j&&a[i] <= pivot) i++; 
		a[j] = a[i];		
	}
	a[i] = pivot;/*将i所对应的a[i]值等于枢纽元交换,从而i左边的值都小于a[i],i右边的值都大于a[i].
	             a[0],也就是选为枢纽元的值，在while语句中的a[i]=a[j]中时已经被替换了*/
	qsort(a, left, i - 1);
	qsort(a, i + 1, right);
}

/*快速排序另外一种写法，经测试无误*/
//void qsort2(int va[], int left, int right){
//
//	if (left >= right) return;
//
//	int l = left + 1;
//	int h = right;
//	int pivot = va[left];
//
//	while (1){
//
//		while (l <= h && va[l] <= pivot) l++;
//		while (l <= h && va[h] >= pivot) h--;
//
//		if (l < h) swap(va[l], va[h]);
//		else break;
//	}
//
//	swap(va[left], va[h]);
//
//	qsort2(va, left, h - 1);
//	qsort2(va, h + 1, right);
//}

int main()
{
	const int SIZE = 10;
	int a[SIZE] = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
	int b[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int c[SIZE] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int d[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	qsort(a, 0, SIZE - 1);
	qsort(b, 0, SIZE - 1);
	qsort(c, 0, SIZE - 1);
	qsort(d, 0, SIZE - 1);
	/*qsort2(a, 0, SIZE - 1);
	qsort2(b, 0, SIZE - 1);
	qsort2(c, 0, SIZE - 1);
	qsort2(d, 0, SIZE - 1);*/
	return 0;
}