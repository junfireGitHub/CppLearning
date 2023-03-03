#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

/*���ڶ���˵����һλ��i�ϵ�Ԫ�أ����������λ��2i���Ҷ���������Ӻ��
��Ԫ��2i+1���У����ĸ�������λ�ã�i/2��������ȡ������*/

void HeapAdjust(int list[], int root, int n)
{
	int child, rootkey;
	rootkey = list[root];
	child = 2 * root;
	while (child <= n)
	{
		if (child < n && list[child] < list[child + 1]) //�����Ǹ����ѣ���С�����Ϊ>
			child++;       /*Ϊʲô��Ҫ�ⲽ������ 65 24 78�����û���ⲽ��
						   ��65 �� 24 �Ƚ�֮�󲻻ύ����
		                   ����ʵ��78>65,���������ѵ�����*/
						   
		/*if else ���Ƿ�����ý���*/
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