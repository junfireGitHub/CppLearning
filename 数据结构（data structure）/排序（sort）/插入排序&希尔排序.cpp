#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

/*��������,�㷨��֤0��λ��i�ϵ�Ԫ��Ϊ������״̬*/
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
/*ϣ������ ����Ȳ�������ֻ��������Ϊ��gap������1*/
//void shellSort(vector<int> a)
//{
//	for (int gap = a.size() / 2; gap > 0; gap /= 2){ //�����и��õ�����
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

