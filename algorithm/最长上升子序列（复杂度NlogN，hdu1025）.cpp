#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>

/*算法原理见 http://www.cnblogs.com/mengxm-lincf/archive/2011/07/12/2104745.html*/
using namespace std;
typedef unsigned int uint;

int *arr, *resArr;

int binSearch(int val, int low, int high)
{
	int mid;
	while (low < high){
		mid = (low + high) / 2;
		if (resArr[mid]>val) high = mid;
		else low = mid + 1;
	}
	return low;
}

int main()
{	
	int n;
	int testNum = 0;
	int index;
	
	while (scanf("%d", &n) != EOF)
	{
		arr = new int[n+1];
		resArr = new int[n + 1];
		int num = n;
		while (num--){
			scanf("%d", &index);
			scanf("%d", &arr[index]);
		}
		int count = 0;
		resArr[count] = arr[1];
		for (int i = 2; i <= n; i++)
		{
			if (arr[i] > resArr[count])
				resArr[++count] = arr[i];
			else{
				int mid = binSearch(arr[i], 0, count);
				resArr[mid] = arr[i];
			}
		}

		printf("Case %d:\n", ++testNum);
		if (count == 0)
			printf("My king, at most 1 road can be built.\n\n");
		else
			printf("My king, at most %d roads can be built.\n\n", count + 1);

		delete[]resArr;
		delete[]arr;
	}
	return 0;
}