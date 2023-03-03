#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

#define LOCAL

bool IsSatisfied(int x, int y, int n)
/* 
判断是否只有一位不同。
通过两者异或后的值是否等于pow(2,n)来判断
*/
{
	for (int i = 0; i < n; i++)
	{
		int num = pow(2, i);
		if ( (x ^ y) == num )
			return true;
	}
	return false;
}
bool isExisted(int *res, int len, int num)
/*判断一个数num是否在res[0...len]中存在*/
{
	for (int i = 0; i < len;i++)
	if (res[i] == num) return true;
	return false;
}
void GetGray(int n,int count,int *rst)
{
	int num = pow(2, n);
	if (IsSatisfied(rst[num - 1], 0, n))//如果格雷码已经找到了，返回
		return;
	if (count == 0)
	{
		rst[count] = 0; //第1个数确定为0
		GetGray(n, count+1, rst);
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			if (isExisted(rst, count, i)) continue; //如果这个数已经存在，则转入下次
			if (IsSatisfied(rst[count - 1], i, n))
			{
				if (IsSatisfied(rst[num - 1], 0, n)) return;//如果格雷码已经找到了，返回
				rst[count] = i;
				GetGray(n, count + 1, rst);
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cout << "please input n: " << endl;
	while (cin >> n)
	{
		int num = pow(2, n);
		int *rst = new int[num];
		memset(rst, 0, num*sizeof(int));

		GetGray(n, 0, rst);
		for (int i = 0; i < num; i++)
			cout <<rst[i]<< endl;
		cout << "please input n: " << endl;
	}
	system("pause");
	return 0;
}

