#include"iostream"
#include"cmath"
#include"string"
#include"cstdlib"
#include"cassert"
using std::cin;
using std::cout;
using std::endl;

//sorce website :   http://www.jisuanke.com/course/8/364

int father[101];

int getRoot(int x)
{	 
	//return father[x]==x? x:getRoot(father[x]);
	/*并查集的一个优化叫做【路径压缩】，是在并查集执行查询时对经过的点进行【扁平化】的方法。
	使得下次查询时不需要经过中间节点，代码如下*/
    if(father[x]!= x) father[x] = getRoot(father[x]) ;
	return father[x];
}

bool merge(int x, int y)
{
	int rx = getRoot(x);
	int ry = getRoot(y);
	if(rx != ry)
	{
		father[rx]=y;
		return true;
	}
    else
	    return false;
}

int main()
{
	int n,num;
	int x,y;
	int count=0;
	cin>>n>>num;
    for(int i=1; i<=n; i++)
		father[i] = i;
	while(num--)
	{
		cin>>x>>y;
		if( !merge(x,y) )
			count++;
	}

	cout<<count<<endl;
	return 0 ;
}