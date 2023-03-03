
//N根不同长度的木棍能拼出多少个不同的不等边三角形
//要求必须使用所有木棍
//题目链接 http://www.jisuanke.com/course/8/348
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,l[15];
bool h[10000];
bool is_triangle(int a, int b, int c){
    return !h[a*100+b]&& a && b && c
        && a + b > c && a + c > b && b + c > a
        &&(h[a*100+b] = true);
}/*!h[a*100+b] 是为了确保之前该三角形没有出现过.
 只需要a与b的参数即可，因为三者之和恒定。
*/
int dfs(int index, int a, int b, int c){
    if(index == n){
		/*穷举过后会有相同的分法，
		这里的a<b<c将相同的去除了。
		同时保证a、b、c互不相同*/
        return a<b && b<c && is_triangle(a,b,c);
    }
    return dfs(index + 1 , a + l[index] , b, c)
        +dfs(index + 1, a, b+l[index], c)
        +dfs(index + 1, a, b,c+l[index]);  // 穷举分配
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i =0; i<n; ++i)
        {
            scanf("%d",&l[i]);
        }
        memset(h,0,sizeof(h));
        printf("%d\n",dfs(0,0,0,0));
    }
    return 0;
}