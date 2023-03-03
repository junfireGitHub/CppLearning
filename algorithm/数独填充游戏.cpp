#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<memory.h>
#include<algorithm>

using namespace std;
struct Point
{
	int x;
	int y;
}p[81];

int map[9][9] = {0};
bool flag = false;

bool judge(int num, int k)
{
	int x = p[num].x;
	int y = p[num].y;
	for (int i = 0; i < 9;i++)
	if (i != x&&map[i][y] == k) return false;
	for (int i = 0; i < 9;i++)
	if (i != y&&map[x][i] == k) return false;

	x = p[num].x / 3 * 3;
	y = p[num].y / 3 * 3;

	for (int i = 0; i < 3;i++)
	for (int j = 0; j < 3; j++)
	{
		if (x + i != p[num].x &&y + j != p[num].y&&map[p[num].x][p[num].y] == map[x + i][y + j])
			return false;
	}
	return true;
}

void dfs(int count)
{
	if (count < 0){ flag = true; return; }
	for (int i = 1; i < 10; i++)
	{	
		map[p[count].x][p[count].y] = i;
		if (judge(count, i))
			dfs(count - 1);
		if (flag) return;
		map[p[count].x][p[count].y] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int val;
	int num = 0;
	for (int i = 0; i < 9;i++)
	for (int j = 0; j < 9; j++)
	{
		cin >> val;
		if (val == 0) {
			p[num].x = i;
			p[num++].y = j;
		}
		else
			map[i][j] = val;
	}

	dfs(--num);
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}

	return 0;
}