//网上的代码
#define maxn 110  
#define maxm 10010  
using namespace std;  
int uf[maxn];  
struct edge{  
	int u,v,len;  
}e[maxm];  
bool cmp(const edge &x,const edge &y){  
	return x.len<y.len;  
}  
void init(int n){//初始化并查集  
	for(int i=0;i<=n;i++)uf[i]=i;  
}  
int find(int x){  
	if(x==uf[x])return x;  
	return uf[x]=find(uf[x]);  
}  
int Union(int x,int y){//合并两个集合（如果x,y在同一集合，返回0，否则返回1）  
	x=find(x),y=find(y);  
	if(x!=y){  
		uf[x]=y;  
		return 1;  
	}  
	return 0;  
}  
int Kruskal(int n,int m){//n个点，m条边  
	sort(e,e+m,cmp);//排序  
	int sum=0;//最小生成树的权值和  
	for(int i=0;i<m;i++){//从小到大枚举边  
		int u=e[i].u,v=e[i].v,len=e[i].len;  
		sum+=len*Union(u,v);  
	}  
	return sum;//返回权值和  
}  