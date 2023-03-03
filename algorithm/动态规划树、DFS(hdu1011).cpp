#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;
typedef unsigned int uint;

struct Sroom
{
	int bug;
	int brain;
}room[101];

bool visited[101];
int maxBrain[101][101];
int tmp[101][101];
int adjMat[101][101] = { 0 };
int n, m;

int max(int x, int y)
{
	return x > y ? x : y;
}

void dpTree(int u)
{
	visited[u] = true;
	int r = (room[u].bug + 19) / 20; //the number of troopers needed to clear the bugs
	for (int j = m; j >= r; j--)
		maxBrain[u][j] = tmp[u][j] = room[u].brain;
	for (int v = 1; v <= n; v++)
	{
		if (adjMat[u][v] == 1 && !visited[v])
		{
			dpTree(v);
			for (int j = m; j >= r; j--)
			{
				for (int k = 1; k < j - r + 1; k++)
					tmp[u][j] = max(tmp[u][j], maxBrain[u][j - k] + maxBrain[v][k]);
			}
		}
	}
	for (int j = m; j >= r; j--)
		maxBrain[u][j] = tmp[u][j];
}

int main()
{
	while (cin >> n >> m && n != -1 && m != -1)
	{
		for (int i = 1; i <= n; i++)
			cin >> room[i].bug >> room[i].brain;

		int u, v;
		memset(adjMat, 0, sizeof(adjMat));
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			adjMat[u][v] = adjMat[v][u] = 1;
		}

		memset(visited, 0, sizeof(visited));
		memset(maxBrain, 0, sizeof(maxBrain));

		if (m == 0){
			cout << "0" << endl;
			continue;
		}

		dpTree(1);
		cout << maxBrain[1][m] << endl;
	}

	return 0;
}