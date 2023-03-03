/*线段树，树状数组*/
void cstBTree(int root,int s, int e){
	if(s==e)
		b[root].val = s;
	else
		cstBTree(root*2+1,s,(s+e)/2);
	    cstBTree(root*2+2,s,(s+e)/2);
		b[root].val = min(b[root*2+1].val, b[root*2+2].val);	
}

int query(int root, int s,int e, int qs, int qe){
	if(qe<s||qs>e)
		return INT_MAX;
	else if(qe>e&&qs<s)
		return b[root].val;
	else{
		return min()
	}
		
}

/* 双向广搜
    从初始结点和目标结点开始分别作两次BFS,
    每次选择队列中结点少的一边进行扩展,并且检测两边是否出现了状态重合*/
		
/*二分状态搜索*/

/* A*搜索

        定义一个估计函数 G = g(x) + h(x) . 
		其中g(x)为你实际已经走过的距离,然后其重点就在 h(x) 的选择,
		比如迷宫搜索最短路时,可以选择 h(x)为到终点的曼哈顿距
		离.那么如果用BFS实现,
		那么用一个优先队列,使得每次增广时选择G小的先增广,这
		样搜最优解的希望更大一些.如果是DFS的话,假设我们目前
		已经搜到的最优解为Ans,那么我们再搜另一个状态他的G如
		果大于Ans,那么就没有必要再搜下去了,剪掉...A*的关键就
		在h(x)的选择,一般选择的都是:离目标状态最少还要花费多少步数.
		(当然这并不是说这样是最好的h(x).只是普遍的选择...).
		根据不同的需要,你也可以定义一个更强大的h(x)来,让你的
		搜索快的飞起来~~~*/
		
		
/*完全背包问题http://love-oriented.com/pack/  http://blog.csdn.net/u013445530/article/details/40210587 */
void dpVal(vector<int>&dp, int n, vector<int>v, vector<int>w , int vol){
	for (int i = 1; i <= n; i++){
		for (int j = v[i]; j<=vol; j++){
			//cout << j<<" "<<dp[j] << " ";
			//cout << dp[j - v[i]] + w[i] << " ";
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			//cout << dp[j] << endl;
		}
	}
}
/*0-1背包问题*/
void dpVal(vector<int>&dp, int n, vector<int>v, vector<int>w , int vol){
	for (int i = 1; i <= n; i++){
		for (int j = vol; j>v[i]; j--){
			//cout << j<<" "<<dp[j] << " ";
			//cout << dp[j - v[i]] + w[i] << " ";
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			//cout << dp[j] << endl;
		}
	}
}
/*分组的背包问题*/
for 所有的组k
    for v=V..0
        for 所有的i属于组k
            f[v]=max{f[v],f[v-c[i]]+w[i]}
/*有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。*/
procedure MultiplePack(cost,weight,amount)
    if cost*amount>=V
        CompletePack(cost,weight)
        return
    integer k=1
    while k<amount
        ZeroOnePack(k*cost,k*weight)
        amount=amount-k
        k=k*2
    ZeroOnePack(amount*cost,amount*weight)
	
	
/*最长公共子串问题的几种算法 http://devhui.com/2015/04/21/Longest-Common-Substring/*/
		