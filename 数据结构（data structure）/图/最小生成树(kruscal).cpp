//���ϵĴ���
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
void init(int n){//��ʼ�����鼯  
	for(int i=0;i<=n;i++)uf[i]=i;  
}  
int find(int x){  
	if(x==uf[x])return x;  
	return uf[x]=find(uf[x]);  
}  
int Union(int x,int y){//�ϲ��������ϣ����x,y��ͬһ���ϣ�����0�����򷵻�1��  
	x=find(x),y=find(y);  
	if(x!=y){  
		uf[x]=y;  
		return 1;  
	}  
	return 0;  
}  
int Kruskal(int n,int m){//n���㣬m����  
	sort(e,e+m,cmp);//����  
	int sum=0;//��С��������Ȩֵ��  
	for(int i=0;i<m;i++){//��С����ö�ٱ�  
		int u=e[i].u,v=e[i].v,len=e[i].len;  
		sum+=len*Union(u,v);  
	}  
	return sum;//����Ȩֵ��  
}  