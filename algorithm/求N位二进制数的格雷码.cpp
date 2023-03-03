#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

#define LOCAL

bool IsSatisfied(int x, int y, int n)
/* 
�ж��Ƿ�ֻ��һλ��ͬ��
ͨ�����������ֵ�Ƿ����pow(2,n)���ж�
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
/*�ж�һ����num�Ƿ���res[0...len]�д���*/
{
	for (int i = 0; i < len;i++)
	if (res[i] == num) return true;
	return false;
}
void GetGray(int n,int count,int *rst)
{
	int num = pow(2, n);
	if (IsSatisfied(rst[num - 1], 0, n))//����������Ѿ��ҵ��ˣ�����
		return;
	if (count == 0)
	{
		rst[count] = 0; //��1����ȷ��Ϊ0
		GetGray(n, count+1, rst);
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			if (isExisted(rst, count, i)) continue; //���������Ѿ����ڣ���ת���´�
			if (IsSatisfied(rst[count - 1], i, n))
			{
				if (IsSatisfied(rst[num - 1], 0, n)) return;//����������Ѿ��ҵ��ˣ�����
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

