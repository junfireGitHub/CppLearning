/*�߶�������״����*/
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

/* ˫�����
    �ӳ�ʼ����Ŀ���㿪ʼ�ֱ�������BFS,
    ÿ��ѡ������н���ٵ�һ�߽�����չ,���Ҽ�������Ƿ������״̬�غ�*/
		
/*����״̬����*/

/* A*����

        ����һ�����ƺ��� G = g(x) + h(x) . 
		����g(x)Ϊ��ʵ���Ѿ��߹��ľ���,Ȼ�����ص���� h(x) ��ѡ��,
		�����Թ��������·ʱ,����ѡ�� h(x)Ϊ���յ�������پ�
		��.��ô�����BFSʵ��,
		��ô��һ�����ȶ���,ʹ��ÿ������ʱѡ��GС��������,��
		�������Ž��ϣ������һЩ.�����DFS�Ļ�,��������Ŀǰ
		�Ѿ��ѵ������Ž�ΪAns,��ô����������һ��״̬����G��
		������Ans,��ô��û�б�Ҫ������ȥ��,����...A*�Ĺؼ���
		��h(x)��ѡ��,һ��ѡ��Ķ���:��Ŀ��״̬���ٻ�Ҫ���Ѷ��ٲ���.
		(��Ȼ�Ⲣ����˵��������õ�h(x).ֻ���ձ��ѡ��...).
		���ݲ�ͬ����Ҫ,��Ҳ���Զ���һ����ǿ���h(x)��,�����
		������ķ�����~~~*/
		
		
/*��ȫ��������http://love-oriented.com/pack/  http://blog.csdn.net/u013445530/article/details/40210587 */
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
/*0-1��������*/
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
/*����ı�������*/
for ���е���k
    for v=V..0
        for ���е�i������k
            f[v]=max{f[v],f[v-c[i]]+w[i]}
/*��N����Ʒ��һ������ΪV�ı�������i����Ʒ�����n[i]�����ã�ÿ��������c[i]����ֵ��w[i]��
��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����*/
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
	
	
/*������Ӵ�����ļ����㷨 http://devhui.com/2015/04/21/Longest-Common-Substring/*/
		