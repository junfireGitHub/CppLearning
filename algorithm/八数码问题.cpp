#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include <queue>  
#include <map>  
#include <vector>

using namespace std;
typedef unsigned int uint;

//题目详细解析见 http://blog.csdn.net/a601025382s/article/details/38091457

uint hashCoef[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
const int maxn = 4e5 + 10;

struct node{
	int m[3][3];
	int x, y;//position of 'x'
	int g, h;
	int hashNum;
	bool operator < (const node a)const
	{
		return h + g > a.h + a.g;
	} //作为后面优先队列的优先级的评判标准
};

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char d[10] = "udlr";

int vis[maxn];

struct Path
{
	int pre;
	char ch;
}p[maxn];

int getHash(node p)//获得hash值，康托展开
{
	int ans=0, a[9],k=0;
	for (int i = 0; i < 3;i++)
		for (int j = 0; j < 3; j++)
			a[k++] = p.m[i][j];
	for (int i = 0; i < 9; i++){
		k = 0;
		for (int j = i - 1; j >= 0; j--){
			if (a[j]>a[i])
				k++;
		}
		ans += hashCoef[i] * k;
	}

	return ans;
}

int getH(node p)
/*评估函数，获得评估值  
计算1~8的数字回到原点(12345678x)需要的步数作为评估值*/
{
	int ans=0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (p.m[i][j]) //'x'被置为0了
				ans += abs(i - (p.m[i][j] - 1) / 3) + abs(j - (p.m[i][j] - 1) % 3);
	return ans;
}

void print(int x)
{
	if (p[x].pre == -1)return;
	print(p[x].pre);
	printf("%c", p[x].ch);
}

void A_star(node e)
{
	memset(vis, 0, sizeof(vis));
	int end_ans, xx, yy, k;
	node a, b;
	for (int i = 0; i < 9; i++)
		a.m[i / 3][i % 3] = (i + 1) % 9;//12345678x
	end_ans = getHash(a);
	e.hashNum = getHash(e);
	e.g = 0; e.h = getH(e);
	vis[e.hashNum] = 1;
	p[e.hashNum].pre = -1;
	if (e.hashNum == end_ans){ printf("\n"); return; }

	priority_queue<node>q;
	q.push(e);
	while (!q.empty())
	{
		e = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			xx = e.x + dir[i][0];
			yy = e.y + dir[i][1];
			if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3) continue;
			a = e;
			swap(a.m[e.x][e.y], a.m[xx][yy]);
			k = getHash(a);
			if (vis[k]) continue;
			vis[k] = 1;
			a.hashNum = k;
			a.x = xx;
			a.y = yy;
			a.g++;
			a.h = getH(a);
			p[k].pre = e.hashNum;
			p[k].ch = d[i];
			if (k == end_ans)
			{
				print(k);
				printf("\n");
				return;
			}
			q.push(a);
		}
	}

}

int main()
{
	char a[30];
	while (gets(a))
	{
		int len = strlen(a);
		node p;
		int k=0;
		for (int i = 0; i < len; i++)
		{
			if (a[i]>'0'&&a[i] < '9')
				p.m[k / 3][k % 3] = a[i] - '0';
			else if (a[i] == 'x'){
				p.m[k / 3][k % 3] = 0;
				p.x = k / 3; 
				p.y = k % 3;
			}
			else
				continue;
			k++;
		}

		//判断逆序数
		k = 0;
		for (int i = 0; i < 9; i++)
		{
			if (p.m[i / 3][i % 3] == 0) continue;
			for (int j = 0; j < i; j++)
			{
				if (p.m[j / 3][j % 3]>p.m[i / 3][i % 3])
					k++;
			}
		}
		if (k % 2 == 1) cout << "unsolvable" << endl;//逆序数为奇数，则退出.
		else
			A_star(p);
	}
	return 0;
}