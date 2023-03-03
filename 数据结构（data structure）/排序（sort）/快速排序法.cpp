#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

void qsort(int a[], int left, int right)
{
	if (left >= right) return;

	int pivot = a[left];//������ŦԪ���Բ�ѡΪ��һ��Ԫ�أ���õ���ŦԪ��ѡȡ�����ݽṹ���㷨����C++����
	int i=left, j=right;
	while (i<j){
		/*����ȫ��ͬ��һ�����飬�������û�еȺţ���i,j���ƶ�*/	
		while (i < j&&a[j] >= pivot) j--; //��Ҫi<j������Ϊ�˷�ֹԾ������ı߽�
		a[i] = a[j];                      
		while (i < j&&a[i] <= pivot) i++; 
		a[j] = a[i];		
	}
	a[i] = pivot;/*��i����Ӧ��a[i]ֵ������ŦԪ����,�Ӷ�i��ߵ�ֵ��С��a[i],i�ұߵ�ֵ������a[i].
	             a[0],Ҳ����ѡΪ��ŦԪ��ֵ����while����е�a[i]=a[j]��ʱ�Ѿ����滻��*/
	qsort(a, left, i - 1);
	qsort(a, i + 1, right);
}

/*������������һ��д��������������*/
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