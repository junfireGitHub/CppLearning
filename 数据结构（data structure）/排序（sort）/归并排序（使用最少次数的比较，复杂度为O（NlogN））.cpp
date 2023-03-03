#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> mergeSort(vector<int> &a)
{
	vector<int> tmp(a.size());
	if (a.size() == 1)
		tmp = a;
	else if (a.size() == 2)
	{
		if (a.at(1) < a.at(0))
			swap(a.at(0), a.at(1));
		tmp = a;
	}
	else
	{
		vector<int>::iterator itr = a.begin() + a.size() / 2;
		vector<int> fa(a.begin(), itr);
		vector<int> ba(itr, a.end());
		vector<int> f = mergeSort(fa);
		vector<int> b = mergeSort(ba);
		int k = 0, i = 0, j = 0;
		while (1)
		{
			if (f.at(i) < b.at(j))
				tmp.at(k++) = f.at(i++);
			else
				tmp.at(k++) = b.at(j++);	
			if (i >= f.size() || j >= b.size()) break;		
		}
		while (i < f.size()) 
			tmp.at(k++) = f.at(i++); 
		while (j < b.size())
			tmp.at(k++) = b.at(j++);
	}
	return tmp;
}

int main()
{
	int n,val;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a.at(i);
	vector<int> b = mergeSort(a);
	return 0;
}