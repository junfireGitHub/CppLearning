#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100;
// 下面这个函数实现的是更新最大值，o赋值为o和x的最大值
template <class T>
T updateMax(T& o, const T& x) {
	T temp;
    temp = (o > x) ? o : x;
	return temp;
}

// f数组为动态规划的状态数组
// num数组为读入的数塔
// n为读入的数塔高度
int f[N][N], num[N][N], n;

int main() {
    // 读入n和数塔数组num
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    // step 1 begin: 在这里实现动态规划算法逻辑
    for(int ii = n; ii >=1; ii--)
        for (int jj = 1; jj <= ii; ++jj)
            {
                if(ii == n)
                    f[n][jj] = num[n][jj];
                else
                    f[ii][jj] = num[ii][jj] + updateMax(f[ii+1][jj],f[ii+1][jj+1]); 
            }
    // step 1 end.

    // 定义最终结果变量result，因为是计算最大值，所以初始化为0
    int result = f[1][1];
 
    // 输出最终最大权值和result
    printf("%d\n", result);
    return 0;
}