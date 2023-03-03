/*
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1

输入例子:
4 24

输出例子:
5
*/
/*这道题也可以通过，在bfs里存储dist,但另外再设置一个数组，来保留已经访问
过的点，即已经到达过的距离点，后面其它点再到达该点时，不再处理*/
#include <iostream>
#include <cstdio>
#include<queue>
using namespace std;

int main(){
	int m, n;
	int dist[110000];
	for (int i = 0; i<110000; i++)
		dist[i] = -1;
	while (cin >> n >> m){
		if (n > m){
			cout << "-1" << endl;
			continue;
		}
		queue<int>q;
		q.push(n);
		dist[n] = 0;
		while (!q.empty()){
			int a = q.front();  q.pop();
			for (int i = 2; i*i <= a; i++){
				if (a%i == 0){
					if (a + i <= m && dist[a + i] == -1){
						dist[a + i] = dist[a] + 1;
						q.push(a + i);
						//cout << a + i <<" "<<dist[a+i]<< endl;
					}
					if (a + a / i <= m && dist[a + a / i] == -1){
						dist[a + a / i] = dist[a] + 1;
						q.push(a + a / i);
					}
				}
			}
		}
		cout << dist[m] << endl;
	}
	return 0;
}