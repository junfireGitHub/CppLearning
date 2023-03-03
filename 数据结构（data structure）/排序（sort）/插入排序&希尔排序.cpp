#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

/*插入排序,算法保证0到位置i上的元素为已排序状态*/
void insertionSort(vector<int> &a)
{
	int j,tmp;
	for (int i = 1; i < a.size(); i++)
	{
		tmp = a[i];
		for (j = i-1; j>=0 && a[j] > tmp; j--)
			a[j + 1] = a[j];
		a[j + 1] = tmp;
	}
}
/*希尔排序 ，相比插入排序只是增量变为了gap，而非1*/
//void shellSort(vector<int> a)
//{
//	for (int gap = a.size() / 2; gap > 0; gap /= 2){ //可能有更好的增量
//		for (int i = gap; i < a.size(); i++)
//		{
//			int tmp = a[i];
//			int j;
//			for (j = i - gap; j >= 0&&a[j] > tmp; j -= gap)
//				a[j + gap] = a[j];
//			a[j + gap] = tmp;
//		}
//	}
//}

int main()
{
	int n,val;
	vector<int> a;
	cin >> n;
	while (n--)
	{
		cin >> val;
		a.push_back(val);
	}
	insertionSort(a);
	//cout << a << endl;
	return 0;
}

